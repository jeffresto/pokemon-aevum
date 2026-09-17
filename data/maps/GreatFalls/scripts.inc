@ Pokémon Aevum — GREAT FALLS
@ Placeholder map script file.

GreatFalls_MapScripts::
    .byte 0

@ ===== AEVUM EVOLUTION CACHE BEGIN =====
GreatFalls_EventScript_AevumEvolutionCache::
    lockall
    goto_if_set FLAG_AEVUM_CACHE_GREAT_FALLS, GreatFalls_EventScript_AevumEvolutionCacheEmpty
    checkitemspace ITEM_MOON_STONE, 1
    goto_if_eq VAR_RESULT, FALSE, GreatFalls_EventScript_AevumEvolutionCacheBagFull
    checkitemspace ITEM_WATER_STONE, 5
    goto_if_eq VAR_RESULT, FALSE, GreatFalls_EventScript_AevumEvolutionCacheBagFull
    checkitemspace ITEM_KINGS_ROCK, 1
    goto_if_eq VAR_RESULT, FALSE, GreatFalls_EventScript_AevumEvolutionCacheBagFull
    giveitem ITEM_MOON_STONE, 1
    giveitem ITEM_WATER_STONE, 5
    giveitem ITEM_KINGS_ROCK, 1
    setflag FLAG_AEVUM_CACHE_GREAT_FALLS
    releaseall
    end

GreatFalls_EventScript_AevumEvolutionCacheEmpty::
    msgbox GreatFalls_Text_AevumEvolutionCacheEmpty, MSGBOX_DEFAULT
    releaseall
    end

GreatFalls_EventScript_AevumEvolutionCacheBagFull::
    msgbox GreatFalls_Text_AevumEvolutionCacheBagFull, MSGBOX_DEFAULT
    releaseall
    end

GreatFalls_Text_AevumEvolutionCacheEmpty:
    .string "The supply cache has already been emptied.$"

GreatFalls_Text_AevumEvolutionCacheBagFull:
    .string "You need more room in your Bag before opening this cache.$"
@ ===== AEVUM EVOLUTION CACHE END =====
