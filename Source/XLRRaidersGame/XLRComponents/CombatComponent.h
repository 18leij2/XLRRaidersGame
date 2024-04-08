// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"


#define TRACE_LENGTH 80000
class AWeapon;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class XLRRAIDERSGAME_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombatComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	friend class ABlasterCharacter;
	
	void EquipWeapon(AWeapon* WeaponToEQuip);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void FireButtonPressed(bool bPressed);

	void TraceUnderCrosshairs(FHitResult& TraceHitResult);

private:
	class ABlasterCharacter* Character;
	class AWeapon* EquippedWeapon;

	bool bFireButtonPressed;

public:	
	// Called every frame

		
};
