// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MMeltManagerComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MELT_API UMMeltManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UMMeltManagerComponent();

	FTimerHandle MeltTimerHandle;
	FTimerDelegate MeltTimerDelegate;
private:
	UPROPERTY(EditAnywhere)
	float MeltSpeed = 2.f;
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	float MaximumMelt = 100.f;

	float CurrentMelt = 0.0f;

	UPROPERTY(EditAnywhere)
	float Temperature = 100.f;

	UPROPERTY(EditAnywhere)
	float MeltInterval = 0.01f;
public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
protected:
	UFUNCTION()
	void ApplyMeltOnce();
	void StartMelting();
};
