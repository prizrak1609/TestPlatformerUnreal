// Fill out your copyright notice in the Description page of Project Settings.


#include "IPawn.h"

// Sets default values
AIPawn::AIPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void AIPawn::NotifyOnDeath()
{
	onDeath.Broadcast();
}

void AIPawn::SetActorHiddenInGame(bool bNewHidden)
{
	if (bNewHidden) {
		onHide.Broadcast();
	}

	Super::SetActorHiddenInGame(bNewHidden);

	if (!bNewHidden) {
		onShow.Broadcast();
	}
}