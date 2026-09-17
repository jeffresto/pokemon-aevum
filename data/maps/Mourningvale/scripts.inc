@ Pokémon Aevum — MOURNINGVALE
@ Placeholder map script file.

Mourningvale_MapScripts::
    .byte 0

@ ===== AEVUM EVOLUTION CACHE BEGIN =====
Mourningvale_EventScript_AevumEvolutionCache::
    lockall
    goto_if_set FLAG_AEVUM_CACHE_MOURNINGVALE, Mourningvale_EventScript_AevumEvolutionCacheEmpty
    checkitemspace ITEM_DUSK_STONE, 2
    goto_if_eq VAR_RESULT, FALSE, Mourningvale_EventScript_AevumEvolutionCacheBagFull
    checkitemspace ITEM_SHINY_STONE, 2
    goto_if_eq VAR_RESULT, FALSE, Mourningvale_EventScript_AevumEvolutionCacheBagFull
    checkitemspace ITEM_REAPER_CLOTH, 1
    goto_if_eq VAR_RESULT, FALSE, Mourningvale_EventScript_AevumEvolutionCacheBagFull
    giveitem ITEM_DUSK_STONE, 2
    giveitem ITEM_SHINY_STONE, 2
    giveitem ITEM_REAPER_CLOTH, 1
    setflag FLAG_AEVUM_CACHE_MOURNINGVALE
    releaseall
    end

Mourningvale_EventScript_AevumEvolutionCacheEmpty::
    msgbox Mourningvale_Text_AevumEvolutionCacheEmpty, MSGBOX_DEFAULT
    releaseall
    end

Mourningvale_EventScript_AevumEvolutionCacheBagFull::
    msgbox Mourningvale_Text_AevumEvolutionCacheBagFull, MSGBOX_DEFAULT
    releaseall
    end

Mourningvale_Text_AevumEvolutionCacheEmpty:
    .string "The supply cache has already been emptied.$"

Mourningvale_Text_AevumEvolutionCacheBagFull:
    .string "You need more room in your Bag before opening this cache.$"
@ ===== AEVUM EVOLUTION CACHE END =====
