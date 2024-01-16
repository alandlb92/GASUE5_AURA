// Copyright Faya Games


#include "UI/Widgets/AuraUserWidget.h"

void UAuraUserWidget::SetWidgetController(UObject* InWidgetController)
{
	Controller = InWidgetController;
	WidgetControllerSet();
}
