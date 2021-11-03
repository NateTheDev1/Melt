// Fill out your copyright notice in the Description page of Project Settings.


#include "MMeltManagerComponent.h"

UMMeltManagerComponent::UMMeltManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UMMeltManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentMelt = MaximumMelt;

	StartMelting();
}

void UMMeltManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                           FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UMMeltManagerComponent::ApplyMeltOnce()
{
	CurrentMelt -= MeltInterval * Temperature;
	UE_LOG(LogTemp, Warning, TEXT("%f"), CurrentMelt);
}

void UMMeltManagerComponent::StartMelting()
{
	MeltTimerDelegate.BindUFunction(this, FName("ApplyMeltOnce"));
	GetWorld()->GetTimerManager().SetTimer(MeltTimerHandle, MeltTimerDelegate, MeltSpeed, true);
}
