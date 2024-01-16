// Copyright Faya Games

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Highlight.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UHighlight : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class AURA_API IHighlight
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void HighlightActor() = 0;
	virtual void UnHighlightAction() = 0;
};
