@ Pokémon Aevum — GLACIER PASS
@ Placeholder map script file.

GlacierPass_MapScripts::
    .byte 0

@ ===== AEVUM EVOLUTION CACHE BEGIN =====
GlacierPass_EventScript_AevumEvolutionCache::
    lockall
    goto_if_set FLAG_AEVUM_CACHE_GLACIER, GlacierPass_EventScript_AevumEvolutionCacheEmpty
    checkitemspace ITEM_DAWN_STONE, 2
    goto_if_eq VAR_RESULT, FALSE, GlacierPass_EventScript_AevumEvolutionCacheBagFull
    checkitemspace ITEM_RAZOR_CLAW, 1
    goto_if_eq VAR_RESULT, FALSE, GlacierPass_EventScript_AevumEvolutionCacheBagFull
    giveitem ITEM_DAWN_STONE, 2
    giveitem ITEM_RAZOR_CLAW, 1
    setflag FLAG_AEVUM_CACHE_GLACIER
    releaseall
    end

GlacierPass_EventScript_AevumEvolutionCacheEmpty::
    msgbox GlacierPass_Text_AevumEvolutionCacheEmpty, MSGBOX_DEFAULT
    releaseall
    end

GlacierPass_EventScript_AevumEvolutionCacheBagFull::
    msgbox GlacierPass_Text_AevumEvolutionCacheBagFull, MSGBOX_DEFAULT
    releaseall
    end

GlacierPass_Text_AevumEvolutionCacheEmpty:
    .string "The supply cache has already been emptied.$"

GlacierPass_Text_AevumEvolutionCacheBagFull:
    .string "You need more room in your Bag before opening this cache.$"
@ ===== AEVUM EVOLUTION CACHE END =====
