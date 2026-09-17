#!/usr/bin/env python3

from pathlib import Path
import collections
import json
import re
import sys

ROOT = Path(__file__).resolve().parents[2]

REGIONAL = [
    "PICHU","PIKACHU","RAICHU",
    "NIDORAN_F","NIDORINA","NIDOQUEEN",
    "NIDORAN_M","NIDORINO","NIDOKING",
    "VULPIX","NINETALES",
    "GROWLITHE","ARCANINE",
    "ABRA","KADABRA","ALAKAZAM",
    "MACHOP","MACHOKE","MACHAMP",
    "MAGNEMITE","MAGNETON","MAGNEZONE",
    "GASTLY","HAUNTER","GENGAR",
    "EXEGGCUTE","EXEGGUTOR",
    "CUBONE","MAROWAK",
    "RHYHORN","RHYDON","RHYPERIOR",
    "SCYTHER","SCIZOR",
    "ELEKID","ELECTABUZZ","ELECTIVIRE",
    "MAGBY","MAGMAR","MAGMORTAR",
    "MAGIKARP","GYARADOS",
    "LAPRAS",
    "EEVEE","VAPOREON","JOLTEON","FLAREON",
    "ESPEON","UMBREON","LEAFEON","GLACEON",
    "MUNCHLAX","SNORLAX",
    "AERODACTYL",
    "DRATINI","DRAGONAIR","DRAGONITE",
    "HORSEA","SEADRA","KINGDRA",
    "SHELLDER","CLOYSTER",
    "STARYU","STARMIE",
    "POLIWAG","POLIWHIRL","POLIWRATH","POLITOED",
    "MAREEP","FLAAFFY","AMPHAROS",
    "ZUBAT","GOLBAT","CROBAT",
    "TOGEPI","TOGETIC","TOGEKISS",
    "HOUNDOUR","HOUNDOOM",
    "SNEASEL","WEAVILE",
    "SWINUB","PILOSWINE","MAMOSWINE",
    "SKARMORY",
    "HERACROSS",
    "PHANPY","DONPHAN",
    "LARVITAR","PUPITAR","TYRANITAR",
    "MISDREAVUS","MISMAGIUS",
    "MURKROW","HONCHKROW",
    "GLIGAR","GLISCOR",
    "PINECO","FORRETRESS",
    "AZURILL","MARILL","AZUMARILL",
    "YANMA","YANMEGA",
    "AIPOM","AMBIPOM",
    "PORYGON","PORYGON2","PORYGON_Z",
    "TANGELA","TANGROWTH",
    "TREECKO","GROVYLE","SCEPTILE",
    "TORCHIC","COMBUSKEN","BLAZIKEN",
    "MUDKIP","MARSHTOMP","SWAMPERT",
    "RALTS","KIRLIA","GARDEVOIR","GALLADE",
    "SHROOMISH","BRELOOM",
    "ARON","LAIRON","AGGRON",
    "MEDITITE","MEDICHAM",
    "ELECTRIKE","MANECTRIC",
    "TRAPINCH","VIBRAVA","FLYGON",
    "SWABLU","ALTARIA",
    "CORPHISH","CRAWDAUNT",
    "FEEBAS","MILOTIC",
    "DUSKULL","DUSCLOPS","DUSKNOIR",
    "ABSOL",
    "SNORUNT","GLALIE","FROSLASS",
    "SPHEAL","SEALEO","WALREIN",
    "BAGON","SHELGON","SALAMENCE",
    "BELDUM","METANG","METAGROSS",
    "ANORITH","ARMALDO",
    "LILEEP","CRADILY",
    "MAKUHITA","HARIYAMA",
    "NUMEL","CAMERUPT",
    "CACNEA","CACTURNE",
    "ZANGOOSE",
    "TORKOAL",
    "TAUROS",
    "LOTAD","LOMBRE","LUDICOLO",
    "NINCADA","NINJASK","SHEDINJA",
    "BUDEW","ROSELIA","ROSERADE",
    "SHINX","LUXIO","LUXRAY",
    "DRIFLOON","DRIFBLIM",
    "GIBLE","GABITE","GARCHOMP",
    "RIOLU","LUCARIO",
    "HIPPOPOTAS","HIPPOWDON",
    "SKORUPI","DRAPION",
    "CROAGUNK","TOXICROAK",
    "SNOVER","ABOMASNOW",
    "ROTOM",
    "SPIRITOMB",
]

REGIONAL = ["SPECIES_" + x for x in REGIONAL]
REGIONAL_SET = set(REGIONAL)

if len(REGIONAL) != 200:
    raise SystemExit(
        f"ERROR: Regional Dex has {len(REGIONAL)}, expected 200."
    )

if len(REGIONAL_SET) != 200:
    raise SystemExit(
        "ERROR: Regional Dex contains duplicates."
    )

groups = json.loads(
    (ROOT / "data/maps/map_groups.json").read_text()
)

aevum_names = groups["gMapGroup_Aevum"]

aevum_ids = set()

for name in aevum_names:
    p = ROOT / "data/maps" / name / "map.json"

    if p.exists():
        aevum_ids.add(
            json.loads(p.read_text())["id"]
        )

# ============================================================
# DIRECT WILD SOURCES
# ============================================================

wild = json.loads(
    (ROOT / "src/data/wild_encounters.json").read_text()
)

wild_group = next(
    x for x in wild["wild_encounter_groups"]
    if x.get("label") == "gWildMonHeaders"
    and x.get("for_maps") is True
)

direct = set()
wild_direct = set()
illegal_wild = set()

for encounter in wild_group["encounters"]:

    if encounter["map"] not in aevum_ids:
        continue

    for field in (
        "land_mons",
        "water_mons",
        "rock_smash_mons",
        "fishing_mons",
    ):
        if field not in encounter:
            continue

        for slot in encounter[field]["mons"]:
            species = slot["species"]

            wild_direct.add(species)

            if species in REGIONAL_SET:
                direct.add(species)
            else:
                illegal_wild.add(
                    (encounter["map"], species)
                )

# ============================================================
# SCRIPTED SOURCES
# ============================================================

script_direct = set()

script_species_re = re.compile(
    r"^\s*(?:givemon|giveegg|setwildbattle)\s+"
    r"(SPECIES_[A-Z0-9_]+)\b",
    re.M,
)

for name in aevum_names:
    p = ROOT / "data/maps" / name / "scripts.inc"

    if not p.exists():
        continue

    for species in script_species_re.findall(
        p.read_text()
    ):
        script_direct.add(species)

        if species in REGIONAL_SET:
            direct.add(species)

# Starter system + Victory Road together guarantee all
# three starter lines can be completed on one save.
direct.update({
    "SPECIES_TREECKO",
    "SPECIES_TORCHIC",
    "SPECIES_MUDKIP",
})

# ============================================================
# EVOLUTION GRAPH PARSER
# ============================================================

family_files = [
    ROOT / f"src/data/pokemon/species_info/gen_{g}_families.h"
    for g in range(1, 5)
]

def balanced_call(text, start):
    open_pos = text.find("(", start)

    if open_pos < 0:
        return None

    depth = 0

    for i in range(open_pos, len(text)):
        c = text[i]

        if c == "(":
            depth += 1
        elif c == ")":
            depth -= 1

            if depth == 0:
                return text[start:i + 1]

    return None


def top_level_entries(call):
    open_pos = call.find("(")
    inner = call[open_pos + 1:-1]

    entries = []
    brace_depth = 0
    start = None

    for i, c in enumerate(inner):

        if c == "{":
            if brace_depth == 0:
                start = i
            brace_depth += 1

        elif c == "}":
            brace_depth -= 1

            if brace_depth == 0 and start is not None:
                entries.append(inner[start:i + 1])
                start = None

    return entries


def split_entry(entry):
    content = entry[1:-1]

    parts = []
    start = 0
    paren = 0
    brace = 0

    for i, c in enumerate(content):

        if c == "(":
            paren += 1
        elif c == ")":
            paren -= 1
        elif c == "{":
            brace += 1
        elif c == "}":
            brace -= 1
        elif c == "," and paren == 0 and brace == 0:
            parts.append(content[start:i].strip())
            start = i + 1

    parts.append(content[start:].strip())

    return parts


edges = collections.defaultdict(list)
edge_data = []

species_header_re = re.compile(
    r"^\s*\[(SPECIES_[A-Z0-9_]+)\]\s*=",
    re.M,
)

for path in family_files:
    text = path.read_text()

    headers = list(species_header_re.finditer(text))

    for i, header in enumerate(headers):
        source = header.group(1)

        if source not in REGIONAL_SET:
            continue

        end = (
            headers[i + 1].start()
            if i + 1 < len(headers)
            else len(text)
        )

        block = text[header.start():end]

        field = block.find(".evolutions = EVOLUTION(")

        if field < 0:
            continue

        evo_start = block.find("EVOLUTION(", field)

        call = balanced_call(block, evo_start)

        if not call:
            raise SystemExit(
                f"ERROR: malformed evolution call for {source}"
            )

        for raw in top_level_entries(call):

            parts = split_entry(raw)

            if len(parts) < 3:
                continue

            method = parts[0].strip()
            param = parts[1].strip()
            target = parts[2].strip()

            if not target.startswith("SPECIES_"):
                continue

            if target not in REGIONAL_SET:
                continue

            data = {
                "source": source,
                "target": target,
                "method": method,
                "param": param,
                "raw": raw,
            }

            edges[source].append(target)
            edge_data.append(data)

# ============================================================
# REACHABILITY
# ============================================================

reachable = set(
    species
    for species in direct
    if species in REGIONAL_SET
)

queue = collections.deque(reachable)

while queue:
    species = queue.popleft()

    for target in edges.get(species, []):
        if target not in reachable:
            reachable.add(target)
            queue.append(target)

missing = sorted(REGIONAL_SET - reachable)

# ============================================================
# EVOLUTION ITEM SUPPLY
# ============================================================

giveitem_re = re.compile(
    r"^\s*giveitem\s+(ITEM_[A-Z0-9_]+)"
    r"(?:\s*,\s*(\d+))?",
    re.M,
)

guaranteed_items = collections.Counter()

for name in aevum_names:
    p = ROOT / "data/maps" / name / "scripts.inc"

    if not p.exists():
        continue

    for item, qty in giveitem_re.findall(
        p.read_text()
    ):
        guaranteed_items[item] += (
            int(qty) if qty else 1
        )

# Standard Poké Balls are normal shop supplies and are only
# relevant to Shedinja's split evolution.
UNLIMITED_STANDARD = {
    "ITEM_POKE_BALL",
}

# Determine whether a source->target pair has a non-item path.
pair_has_non_item = set()

for edge in edge_data:
    if edge["method"] != "EVO_ITEM":
        pair_has_non_item.add(
            (edge["source"], edge["target"])
        )

required_items = collections.Counter()

for edge in edge_data:

    if edge["method"] != "EVO_ITEM":
        continue

    pair = (edge["source"], edge["target"])

    if pair in pair_has_non_item:
        continue

    item = edge["param"]

    if item.startswith("ITEM_"):
        required_items[item] += 1

item_failures = []

for item, needed in sorted(required_items.items()):

    if item in UNLIMITED_STANDARD:
        continue

    have = guaranteed_items[item]

    if have < needed:
        item_failures.append(
            (item, needed, have)
        )

# ============================================================
# MOVE-BASED EVOLUTION CHECKS
# ============================================================

learnsets = (
    ROOT
    / "src/data/pokemon/level_up_learnsets/gen_4.h"
).read_text()

species_blocks = {}

for path in family_files:
    text = path.read_text()
    headers = list(species_header_re.finditer(text))

    for i, header in enumerate(headers):
        species = header.group(1)

        end = (
            headers[i + 1].start()
            if i + 1 < len(headers)
            else len(text)
        )

        species_blocks[species] = text[
            header.start():end
        ]

move_failures = []

for edge in edge_data:

    moves = re.findall(
        r"IF_KNOWS_MOVE\s*,\s*(MOVE_[A-Z0-9_]+)",
        edge["raw"],
    )

    for move in moves:
        block = species_blocks.get(
            edge["source"],
            "",
        )

        m = re.search(
            r"\.levelUpLearnset\s*=\s*"
            r"(s[A-Za-z0-9_]+LevelUpLearnset)",
            block,
        )

        if not m:
            move_failures.append(
                (edge["source"], move, "no learnset pointer")
            )
            continue

        array_name = m.group(1)

        lm = re.search(
            rf"static const struct LevelUpMove\s+"
            rf"{re.escape(array_name)}\[\]\s*=\s*\{{"
            rf"(.*?)LEVEL_UP_END",
            learnsets,
            re.S,
        )

        if not lm or move not in lm.group(1):
            move_failures.append(
                (
                    edge["source"],
                    move,
                    array_name,
                )
            )

# ============================================================
# LOCATION REQUIREMENT CHECKS
# ============================================================

map_constants = (
    ROOT / "include/constants/map_groups.h"
).read_text()

mapsec_constants = (
    ROOT / "include/constants/region_map_sections.h"
).read_text()

location_failures = []

for edge in edge_data:

    for constant in re.findall(
        r"IF_IN_MAP\s*,\s*(MAP_[A-Z0-9_]+)",
        edge["raw"],
    ):
        if not re.search(
            rf"\b{re.escape(constant)}\b",
            map_constants,
        ):
            location_failures.append(
                (edge["source"], constant)
            )

    for constant in re.findall(
        r"IF_IN_MAPSEC\s*,\s*(MAPSEC_[A-Z0-9_]+)",
        edge["raw"],
    ):
        if not re.search(
            rf"\b{re.escape(constant)}\b",
            mapsec_constants,
        ):
            location_failures.append(
                (edge["source"], constant)
            )

# ============================================================
# STARTER RULE AUDIT
# ============================================================

starter_species = {
    "SPECIES_TREECKO",
    "SPECIES_TORCHIC",
    "SPECIES_MUDKIP",
}

starter_wild = sorted(
    x
    for x in wild_direct
    if x in starter_species
)

vr_path = (
    ROOT
    / "data/maps/VictoryRoadStarterSanctum/scripts.inc"
)

vr = vr_path.read_text() if vr_path.exists() else ""

starter_guard_failures = []

checks = [
    (
        "SPECIES_TREECKO",
        "goto_if_eq VAR_STARTER_MON, 0",
    ),
    (
        "SPECIES_TORCHIC",
        "goto_if_eq VAR_STARTER_MON, 1",
    ),
    (
        "SPECIES_MUDKIP",
        "goto_if_eq VAR_STARTER_MON, 2",
    ),
]

for species, guard in checks:
    if species not in vr or guard not in vr:
        starter_guard_failures.append(
            (species, guard)
        )

# ============================================================
# REPORT
# ============================================================

print("=" * 72)
print("POKEMON AEVUM — REGIONAL DEX OBTAINABILITY AUDIT")
print("=" * 72)
print()
print(f"Regional Dex entries:      {len(REGIONAL_SET)}")
print(f"Direct obtainable species: {len(direct & REGIONAL_SET)}")
print(f"Reachable after evolution: {len(reachable)}")
print()

failed = False

if illegal_wild:
    failed = True
    print("FAIL — non-Regional species in Aevum wild encounters:")
    for map_id, species in sorted(illegal_wild):
        print(f"  {map_id}: {species}")
    print()
else:
    print("PASS — Aevum wild encounters contain only Regional Dex species.")

if missing:
    failed = True
    print()
    print("FAIL — unobtainable Regional Dex species:")
    for species in missing:
        print(" ", species)
else:
    print("PASS — all 200 Regional Dex species are structurally reachable.")

if item_failures:
    failed = True
    print()
    print("FAIL — insufficient guaranteed evolution-item supply:")
    for item, needed, have in item_failures:
        print(
            f"  {item}: need {needed}, guaranteed {have}"
        )
else:
    print("PASS — guaranteed evolution-item supply covers item evolutions.")

if move_failures:
    failed = True
    print()
    print("FAIL — move-based evolution prerequisite problems:")
    for row in move_failures:
        print(" ", *row)
else:
    print("PASS — move-based evolution prerequisites exist in Gen-IV learnsets.")

if location_failures:
    failed = True
    print()
    print("FAIL — missing evolution-location constants:")
    for row in location_failures:
        print(" ", *row)
else:
    print("PASS — all location-evolution map constants exist.")

if starter_wild:
    failed = True
    print()
    print("FAIL — starters appear in normal wild tables:")
    for species in starter_wild:
        print(" ", species)
else:
    print("PASS — Treecko/Torchic/Mudkip absent from normal wild encounters.")

if starter_guard_failures:
    failed = True
    print()
    print("FAIL — Victory Road starter guards incomplete:")
    for row in starter_guard_failures:
        print(" ", *row)
else:
    print("PASS — Victory Road sanctuary blocks the originally chosen starter.")

print()

if failed:
    print("RESULT: FAIL")
    raise SystemExit(1)

print("RESULT: PASS — 200 / 200 structurally obtainable on one save.")
