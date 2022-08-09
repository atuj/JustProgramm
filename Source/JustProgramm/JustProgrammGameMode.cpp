// Copyright Epic Games, Inc. All Rights Reserved.

#include "JustProgrammGameMode.h"
#include "JustProgrammCharacter.h"
#include "SandBoxPawn.h"
#include "UObject/ConstructorHelpers.h"

AJustProgrammGameMode::AJustProgrammGameMode()
{

	DefaultPawnClass = ASandBoxPawn::StaticClass();
	
}
