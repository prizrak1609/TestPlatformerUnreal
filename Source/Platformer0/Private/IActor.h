// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHide);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShow);

UCLASS()
class AIActor : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = CustomEvents)
	FOnHide onHide;

	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = CustomEvents)
	FOnShow onShow;

	// Sets default values for this actor's properties
	AIActor();

	void SetActorHiddenInGame(bool bNewHidden) override;

};
