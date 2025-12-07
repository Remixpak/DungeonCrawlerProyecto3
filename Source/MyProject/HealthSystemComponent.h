
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthSystemComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDamageReceived);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Blueprintable)
class MYPROJECT_API UHealthSystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHealthSystemComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealth;


	UFUNCTION(BlueprintCallable)
	void ReceiveDamage(float DamageAmount);


	UPROPERTY(BlueprintAssignable, Category = "Event")
	FOnDamageReceived OnDamageReceived;
};
