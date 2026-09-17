
GreatFallsHiddenCavern_MapScripts::
    .byte 0

@ ===== AEVUM LAPRAS STATIC BEGIN =====
GreatFallsHiddenCavern_EventScript_Lapras::
    lockall
    goto_if_set FLAG_AEVUM_CAUGHT_STATIC_LAPRAS, GreatFallsHiddenCavern_EventScript_LaprasGone
    msgbox GreatFallsHiddenCavern_Text_LaprasPrompt, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, GreatFallsHiddenCavern_EventScript_LaprasCancel
    setwildbattle SPECIES_LAPRAS, 28, ITEM_NONE
    dowildbattle
    specialvar VAR_RESULT, GetBattleOutcome
    goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, GreatFallsHiddenCavern_EventScript_LaprasCaught
    msgbox GreatFallsHiddenCavern_Text_LaprasRetry, MSGBOX_DEFAULT
    releaseall
    end

GreatFallsHiddenCavern_EventScript_LaprasCaught::
    setflag FLAG_AEVUM_CAUGHT_STATIC_LAPRAS
    msgbox GreatFallsHiddenCavern_Text_LaprasCaught, MSGBOX_DEFAULT
    releaseall
    end

GreatFallsHiddenCavern_EventScript_LaprasGone::
    msgbox GreatFallsHiddenCavern_Text_LaprasGone, MSGBOX_DEFAULT
    releaseall
    end

GreatFallsHiddenCavern_EventScript_LaprasCancel::
    releaseall
    end

GreatFallsHiddenCavern_Text_LaprasPrompt:
    .string "A LAPRAS watches you from the underground pool. Approach?$"

GreatFallsHiddenCavern_Text_LaprasRetry:
    .string "LAPRAS slipped away. It may return if you try again.$"

GreatFallsHiddenCavern_Text_LaprasCaught:
    .string "The cavern is quiet after your encounter with LAPRAS.$"

GreatFallsHiddenCavern_Text_LaprasGone:
    .string "Only ripples remain in the underground pool.$"
@ ===== AEVUM LAPRAS STATIC END =====
