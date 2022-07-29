// Fill out your copyright notice in the Description page of Project Settings.


#include "AActor.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseActor,All,All);

// Sets default values
AAActor::AAActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	SetRootComponent(BaseMesh);

}

// Called when the game starts or when spawned
void AAActor::BeginPlay()
{
	Super::BeginPlay();
	
	//printTypes()
	//printStringTypes()
	 UE_LOG(LogBaseActor,Display,TEXT("Info"));
}

// Called every frame
void AAActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAActor::printTypes()
{


	UE_LOG(LogBaseActor, Display,TEXT("Weapons num: %d, kills num %i"), WeaponsNum, KillsNum);
	UE_LOG(LogBaseActor, Display,TEXT("Health: %.2f"), Health);
	UE_LOG(LogBaseActor, Display,TEXT("IsDead: %d, HasWeapon: %i"), IsDead, static_cast<int>(HasWeapon));	
}

void AAActor::printStringTypes()
{
	FString Name = "John Connor";
	UE_LOG(LogBaseActor,Display,TEXT("Name: %s"),*Name);
	

	FString WeaponsNumStr = "Weapons num = " + FString::FromInt(WeaponsNum);
	FString HealthStr = "Health = "+ FString::SanitizeFloat(Health);
	FString IsDeadStr = "Is dead = "+ FString(IsDead?"True":"False");

	FString Stat = FString::Printf(TEXT("\n == All stat ==\n %s \n %s \n %s "),*WeaponsNumStr,*HealthStr,*IsDeadStr);
	UE_LOG(LogBaseActor,Warning,TEXT("%s"),*Stat);

	GEngine->AddOnScreenDebugMessage(-1,3.0f,FColor::Purple,Name);
	GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Green,Stat,true,FVector2D(1.5f,1.5f));
}
