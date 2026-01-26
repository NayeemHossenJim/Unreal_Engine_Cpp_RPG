#include "Items/Item.h"
#include "Slash/DebugMacros.h"
#include "DrawDebugHelpers.h"

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AItem::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();
	FVector Location = GetActorLocation();
	FVector Forward = GetActorForwardVector();

	DRAW_SPHERE(Location);
	DRAW_VECTOR(Location, Location + Forward * 100.f);
	DRAW_BOX(Location, FVector(20.f));

}

void AItem::Tick(float DeltaTime)
{

}