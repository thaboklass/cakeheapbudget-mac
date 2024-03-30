/**
 CakeHeap Budget for Mac
 priority.h
 Purpose: A base class used by others to measure priority.
 
 @author Thabo David Nyakallo Klass
 @version 1.0 8/9/16
 */

#ifndef PRIORITY_H_INCLUDED
#define PRIORITY_H_INCLUDED

enum PriorityLevel { HIGH, MEDIUM, LOW, NONE };

class Priority
{
    public:
        Priority(PriorityLevel pLevel);
        ~Priority() {}
        PriorityLevel getPriority() const;
        void setPriority(PriorityLevel pLevel);
    private:
        PriorityLevel itsPriorityLevel;
};
#endif // PRIORITY_H_INCLUDED
