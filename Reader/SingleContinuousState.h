#ifndef SINGLECONTINUOUSSTATE_H
#define SINGLECONTINUOUSSTATE_H

#include "ViewState.h"

class SingleContinuousState : public ViewState
{
    SingleContinuousState(ViewModel* viewModel);
    virtual ~SingleContinuousState();

public:
    virtual void RenderPages(QPainter* paint);

public:
    ViewModel*      m_ViewModel;


};

#endif // SINGLECONTINUOUSSTATE_H
