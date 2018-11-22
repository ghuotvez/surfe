#include "modelling_parameters.h"

//Wrapper to create a model parameter instance
void* Create_ModelParameters_Instance()
{
	model_parameters* mp = new model_parameters();
	return mp;
}
//Wrapper to release a model parameter instance
void Release_ModelParameters_Instance(void* mpInstance)
{
	model_parameters* mp = (model_parameters*)mpInstance;
	delete mp;
}