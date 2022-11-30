// Fill out your copyright notice in the Description page of Project Settings.


#include "HelperFunctions.h"

TArray<USceneComponent*> UHelperFunctions::Sort(TArray<USceneComponent*> components, bool UnsortedAtTheEnd)
{
	TArray<USceneComponent*> componentsToSort;
	for (USceneComponent* component : components) {
		if (!component->ComponentTags.IsEmpty() && component->ComponentTags[0].ToString() != getIgnoreTag()) {
			componentsToSort.Add(component);
		}
	}

	for (int i = 0; i < componentsToSort.Num(); i++) {
		USceneComponent* component = componentsToSort[i];
		int order = FCString::Atoi(*(component->ComponentTags[0].ToString()));
		USceneComponent* tmp = componentsToSort[order];
		componentsToSort[order] = component;
		componentsToSort[i] = tmp;
	}

	for (USceneComponent* component : components) {
		if (!componentsToSort.Contains(component)) {
			if (UnsortedAtTheEnd) {
				componentsToSort.Add(component);
			}
			else {
				componentsToSort.Insert(component, 0);
			}
		}
	}

	return componentsToSort;
}

FString UHelperFunctions::getIgnoreTag()
{
	return "Ignore";
}
