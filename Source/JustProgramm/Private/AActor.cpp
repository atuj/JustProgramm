// Fill out your copyright notice in the Description page of Project Settings.


#include "AActor.h"
#include "Engine/Engine.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "TimerManager.h"

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
	
    InitialLocation = GetActorLocation();
	
	
	//printTypes()
	//printStringTypes()
	 UE_LOG(LogBaseActor,Display,TEXT("Info"));

	SetColor(GeometryData.Color);

	GetWorldTimerManager().SetTimer(TimerHandle, this, &AAActor::OnTimerFired,GeometryData.TimerRate,true);
		
}
void AAActor::SetColor(const FLinearColor &Color)
{
	if(!BaseMesh) return;
	UMaterialInstanceDynamic* DynMaterial = BaseMesh->CreateAndSetMaterialInstanceDynamic(0);
	if (DynMaterial)
	{
		DynMaterial->SetVectorParameterValue("Color",Color);
	}
}

void AAActor::OnTimerFired()
{
	if (++TimerCount <= MaxTimerCount)
	{
		const FLinearColor NewColor = FLinearColor::MakeRandomColor();
		UE_LOG(LogBaseActor,Display,TEXT("color: %s"), *NewColor.ToString());
		SetColor(NewColor);
	}
	else
	{
		UE_LOG(LogBaseActor,Warning,TEXT("Timer has been stoped"));
		GetWorldTimerManager().ClearTimer(TimerHandle);
	}
	
}


// Called every frame
void AAActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	HandleMovement();
	
}
void AAActor::HandleMovement()
{
	switch(GeometryData.MoveType)
	{
	case EMovementType::Sin:
		{
			FVector CurrentLocation = GetActorLocation();
			if(GetWorld())
			{
				float time = GetWorld()->GetTimeSeconds();
				CurrentLocation.Z = InitialLocation.Z + GeometryData.Amplitude * FMath::Sin(GeometryData.Frequency*time);
				SetActorLocation(CurrentLocation);
			}
		}
	case EMovementType::Static: break;
	default: break;
	}
}


void AAActor::printFtransform()
{
    FTransform Transform = GetActorTransform();
	FVector Location = Transform.GetLocation();
	FRotator Rotator = Transform.Rotator();
	FVector Scale = Transform.GetScale3D();

	UE_LOG(LogBaseActor,Display,TEXT("Transform %s"), *Transform.ToString());
	UE_LOG(LogBaseActor,Display,TEXT("Location %s"), *Location.ToString());
	UE_LOG(LogBaseActor,Display,TEXT("Rotator %S"), *Rotator.ToString());
	UE_LOG(LogBaseActor,Display,TEXT("Scale %s"), *Scale.ToString());
	UE_LOG(LogBaseActor,Error,TEXT("Transform v2 %s"), *Transform.ToHumanReadableString());
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

	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1,3.0f,FColor::Purple,Name);
		GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Green,Stat,true,FVector2D(1.5f,1.5f));
	}
	
}

