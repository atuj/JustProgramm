// Copyright Epic Games, Inc. All Rights Reserved.

#include "JustProgrammGameMode.h"
#include "JustProgrammCharacter.h"
#include "UObject/ConstructorHelpers.h"

AJustProgrammGameMode::AJustProgrammGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
