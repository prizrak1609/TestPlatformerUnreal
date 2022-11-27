// Fill out your copyright notice in the Description page of Project Settings.


#include "IActor.h"

// Sets default values
AIActor::AIActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void AIActor::UnregisterAllComponents(bool bForReregister)
{
	OnBeginDestroy.Broadcast();

	Super::UnregisterAllComponents(bForReregister);
}
