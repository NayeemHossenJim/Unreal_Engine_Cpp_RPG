#include "Items/Item.h"
#include "DrawDebugHelpers.h"

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Item Begin Play"));

	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Item Begin Play"));
	}

	UWorld* World = GetWorld();
	if (World)
	{
		DrawDebugSphere(World, GetActorLocation(), 30.f, 12, FColor::Red, true, 10.f);
	}
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("DeltaTime: %f"), DeltaTime);

	if (GEngine)
	{
		FString Name = GetName();
		FString Message = FString::Printf(TEXT("Item Name: %s"), *Name);
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, Message);

		UE_LOG(LogTemp, Warning, TEXT("Item Name: %s"), *Name);
	}


}