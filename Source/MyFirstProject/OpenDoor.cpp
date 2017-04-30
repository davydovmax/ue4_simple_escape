// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFirstProject.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
    FRotator rotator = FRotator(0.0f, 5.0f, 0.0f);
    GetOwner()->SetActorRotation(rotator);

    ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

// Called when the game starts
void UOpenDoor::OpenDoor()
{
    FRotator rotator = FRotator(0.0f, -OpenAngle, 0.0f);
    GetOwner()->SetActorRotation(rotator);
}

void UOpenDoor::CloseDoor()
{
    FRotator rotator = FRotator(0.0f, 0.0f, 0.0f);
    GetOwner()->SetActorRotation(rotator);
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if(PressurePlate->IsOverlappingActor(ActorThatOpens)) {
        OpenDoor();
    }
    else {
        CloseDoor();
    }
}

