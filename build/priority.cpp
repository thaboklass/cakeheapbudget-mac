#include "priority.h"

/**
 The constructor for the Priority class.
 
 @param the PriorityLevel enum.
 */
Priority::Priority(PriorityLevel pLevel):
itsPriorityLevel(pLevel)
{
}


/**
 The priority getter.
 
 @param none.
 @return the 'priority level' amount.
 */
PriorityLevel Priority::getPriority() const
{
    return itsPriorityLevel;
}


/**
 The priority setter.
 
 @param  the priority level.
 @return nothing.
 */
void Priority::setPriority(PriorityLevel pLevel)
{
    itsPriorityLevel = pLevel;
}
