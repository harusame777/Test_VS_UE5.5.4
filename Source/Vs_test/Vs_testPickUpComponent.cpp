// Copyright Epic Games, Inc. All Rights Reserved.

#include "Vs_testPickUpComponent.h"

UVs_testPickUpComponent::UVs_testPickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UVs_testPickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UVs_testPickUpComponent::OnSphereBeginOverlap);
}

void UVs_testPickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AVs_testCharacter* Character = Cast<AVs_testCharacter>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
