// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "AActor.generated.h"

UCLASS()
class JUSTPROGRAMM_API AAActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAActor();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent *BaseMesh;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere,Category = "Custom")
	int32 WeaponsNum = 3;

	UPROPERTY(EditDefaultsOnly, Category = "Custom")
	int32 KillsNum = 6;
	
	UPROPERTY(EditInstanceOnly, Category = "Custom")	
	float Health = 33.444;

	UPROPERTY(EditAnywhere, Category = "Custom")	
	bool IsDead = false;

	UPROPERTY(VisibleAnywhere, Category = "Custom")	
	bool HasWeapon = true;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	void printTypes();
	void printStringTypes();
};
