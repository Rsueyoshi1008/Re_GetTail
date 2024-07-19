// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPActorBase.h"
#include "Kismet/KismetSystemLibrary.h" // 追加
#include "Kismet/GameplayStatics.h" // 追加
#include "Components/InputComponent.h" // 追加
#include "EnhancedInputComponent.h" // 追加
#include "EnhancedInputSubsystems.h" // 追加


// Sets default values
ACPPActorBase::ACPPActorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPPActorBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPPActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


    

}



