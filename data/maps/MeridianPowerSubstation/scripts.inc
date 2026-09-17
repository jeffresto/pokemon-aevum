@ Pokémon Aevum — Meridian Power Substation
@ Story/static encounters added in a later pass.

MeridianPowerSubstation_MapScripts::
    .byte 0

@ ===== AEVUM ROTOM BEGIN =====
MeridianPowerSubstation_EventScript_Rotom::
    lockall
    goto_if_set FLAG_AEVUM_CAUGHT_ROTOM, MeridianPowerSubstation_EventScript_RotomGone
    msgbox MeridianPowerSubstation_Text_RotomPrompt, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, MeridianPowerSubstation_EventScript_RotomCancel
    setwildbattle SPECIES_ROTOM, 30, ITEM_NONE
    dowildbattle
    specialvar VAR_RESULT, GetBattleOutcome
    goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, MeridianPowerSubstation_EventScript_RotomCaught
    msgbox MeridianPowerSubstation_Text_RotomRetry, MSGBOX_DEFAULT
    releaseall
    end

MeridianPowerSubstation_EventScript_RotomCaught::
    setflag FLAG_AEVUM_CAUGHT_ROTOM
    msgbox MeridianPowerSubstation_Text_RotomCaught, MSGBOX_DEFAULT
    releaseall
    end

MeridianPowerSubstation_EventScript_RotomGone::
    msgbox MeridianPowerSubstation_Text_RotomGone, MSGBOX_DEFAULT
    releaseall
    end

MeridianPowerSubstation_EventScript_RotomCancel::
    releaseall
    end

MeridianPowerSubstation_Text_RotomPrompt:
    .string "A strange presence stirs in the machinery. Investigate?$"

MeridianPowerSubstation_Text_RotomRetry:
    .string "The presence vanished, but energy is gathering again.$"

MeridianPowerSubstation_Text_RotomCaught:
    .string "The strange electrical presence has settled.$"

MeridianPowerSubstation_Text_RotomGone:
    .string "The machinery hums normally now.$"
@ ===== AEVUM ROTOM END =====
