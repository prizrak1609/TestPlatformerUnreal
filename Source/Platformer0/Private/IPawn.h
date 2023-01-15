// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "IPawn.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPawnHide);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPawnShow);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPawnDeath);

UCLASS()
class AIPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AIPawn();

	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = CustomEvents)
	FOnPawnHide onHide;

	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = CustomEvents)
	FOnPawnShow onShow;

	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = CustomEvents)
	FOnPawnDeath onDeath;

	UFUNCTION(BlueprintCallable)
	void NotifyOnDeath();

	void SetActorHiddenInGame(bool bNewHidden) override;
};
