
VerdantHollowArchive_MapScripts::
    .byte 0

@ ===== AEVUM TOGEPI GIFT BEGIN =====
VerdantHollowArchive_EventScript_TogepiEgg::
    lockall
    goto_if_set FLAG_AEVUM_RECEIVED_TOGEPI_EGG, VerdantHollowArchive_EventScript_TogepiAlreadyReceived
    giveegg SPECIES_TOGEPI
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, VerdantHollowArchive_EventScript_TogepiReceived
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, VerdantHollowArchive_EventScript_TogepiReceived
    goto Common_EventScript_NoMoreRoomForPokemon

VerdantHollowArchive_EventScript_TogepiReceived::
    setflag FLAG_AEVUM_RECEIVED_TOGEPI_EGG
    msgbox VerdantHollowArchive_Text_TogepiReceived, MSGBOX_DEFAULT
    releaseall
    end

VerdantHollowArchive_EventScript_TogepiAlreadyReceived::
    msgbox VerdantHollowArchive_Text_TogepiAlreadyReceived, MSGBOX_DEFAULT
    releaseall
    end

VerdantHollowArchive_Text_TogepiReceived:
    .string "HELENA entrusted you with a preserved POKEMON EGG.$"

VerdantHollowArchive_Text_TogepiAlreadyReceived:
    .string "The Archive has no other preserved EGG for you.$"
@ ===== AEVUM TOGEPI GIFT END =====
