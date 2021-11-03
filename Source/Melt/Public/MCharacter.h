// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MMeltManagerComponent.h"
#include "GameFramework/Character.h"
#include "MCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class MELT_API AMCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMCharacter();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	void MoveForward(float Value);

	void MoveRight(float Value);

	void Jump();

	UPROPERTY(VisibleAnywhere)
	UMMeltManagerComponent* MeltManager;
public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
