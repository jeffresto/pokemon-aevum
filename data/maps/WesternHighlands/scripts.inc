@ Pokémon Aevum — WESTERN HIGHLANDS
@ Placeholder map script file.

WesternHighlands_MapScripts::
    .byte 0

@ ===== AEVUM EVOLUTION CACHE BEGIN =====
WesternHighlands_EventScript_AevumEvolutionCache::
    lockall
    goto_if_set FLAG_AEVUM_CACHE_HIGHLANDS, WesternHighlands_EventScript_AevumEvolutionCacheEmpty
    checkitemspace ITEM_FIRE_STONE, 3
    goto_if_eq VAR_RESULT, FALSE, WesternHighlands_EventScript_AevumEvolutionCacheBagFull
    checkitemspace ITEM_RAZOR_FANG, 1
    goto_if_eq VAR_RESULT, FALSE, WesternHighlands_EventScript_AevumEvolutionCacheBagFull
    checkitemspace ITEM_THICK_CLUB, 1
    goto_if_eq VAR_RESULT, FALSE, WesternHighlands_EventScript_AevumEvolutionCacheBagFull
    giveitem ITEM_FIRE_STONE, 3
    giveitem ITEM_RAZOR_FANG, 1
    giveitem ITEM_THICK_CLUB, 1
    setflag FLAG_AEVUM_CACHE_HIGHLANDS
    releaseall
    end

WesternHighlands_EventScript_AevumEvolutionCacheEmpty::
    msgbox WesternHighlands_Text_AevumEvolutionCacheEmpty, MSGBOX_DEFAULT
    releaseall
    end

WesternHighlands_EventScript_AevumEvolutionCacheBagFull::
    msgbox WesternHighlands_Text_AevumEvolutionCacheBagFull, MSGBOX_DEFAULT
    releaseall
    end

WesternHighlands_Text_AevumEvolutionCacheEmpty:
    .string "The supply cache has already been emptied.$"

WesternHighlands_Text_AevumEvolutionCacheBagFull:
    .string "You need more room in your Bag before opening this cache.$"
@ ===== AEVUM EVOLUTION CACHE END =====
