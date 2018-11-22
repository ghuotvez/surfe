// SURFace Estimator(SURFE) - Terms and Conditions of Use

// Unless otherwise noted, computer program source code of the SURFace Estimator(SURFE)
// is covered under Crown Copyright, Government of Canada, and is distributed under the MIT License.

// The Canada wordmark and related graphics associated with this distribution are protected under 
// trademark law and copyright law.No permission is granted to use them outside the parameters of 
// the Government of Canada's corporate identity program. For more information, see
// http://www.tbs-sct.gc.ca/fip-pcim/index-eng.asp

// Copyright title to all 3rd party software distributed with the SURFace Estimator(SURFE) is held 
// by the respective copyright holders as noted in those files.Users are asked to read the 3rd Party
// Licenses referenced with those assets.

// MIT License

// Copyright(c) 2017 Government of Canada

// Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
// and associated documentation files(the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute, 
// sublicense, and / or sell copies of the Software, and to permit persons to whom the Software is 
// furnished to do so, subject to the following conditions :

// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.

//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef modelling_parameters_h
#define modelling_parameters_h

#include <surfe_lib_module.h>

#define D2R 0.01745329251994329576923690768489 // degrees to radians conversion factor
#define R2D 57.295779513082320876798154814105  // radians to degrees conversion factor

struct SURFE_LIB_EXPORT Parameter_Types{
	enum DWRT {PT1,PT2};
	enum SecondDerivatives {DXDX,DXDY,DXDZ,DYDX,DYDY,DYDZ,DZDX,DZDY,DZDZ};
	enum FirstDerivatives {DX,DY,DZ};
	enum RBF {Cubic,Gaussian,MQ,IMQ,TPS,R};
	enum SolverType {Linear,Quadratic};
	enum ModelType {Single_surface,Lajaunie_approach,Stratigraphic_horizons,Continuous_property,Vector_field};
	enum AXIS {Xaxis,Yaxis,Zaxis};
};

struct SURFE_LIB_EXPORT model_parameters{
	////////////////////////////////
	//        UI parameters       //
	////////////////////////////////

	// model type
	Parameter_Types::ModelType model_type;
	double min_stratigraphic_thickness;
	// interface input
	bool use_interface_data;
	bool use_planar_data;
	bool use_tangent;
	bool use_inequality;
	// basis parameters
	Parameter_Types::RBF basis_type;
	double shape_parameter;
	int polynomial_order;

	bool advanced_parameters;
	bool model_global_anisotropy;
	bool use_greedy;
	bool use_restricted_range;
	double interface_uncertainty;
	double angular_uncertainty;

	// initialization ...
	model_parameters() : model_type(Parameter_Types::Single_surface), min_stratigraphic_thickness(0),
		use_interface_data(true), use_planar_data(true), use_tangent(false), use_inequality(false),
		basis_type(Parameter_Types::Cubic), shape_parameter(100), polynomial_order(1),
		advanced_parameters(false), model_global_anisotropy(false), use_greedy(false), use_restricted_range(false), interface_uncertainty(0), angular_uncertainty(0) {}
};

struct SURFE_LIB_EXPORT basic_parameters{
	// number of constraints, for each basic constraint type
	unsigned int n_interface;
	unsigned int n_planar;
	unsigned int n_inequality;
	unsigned int n_tangent;
	unsigned int n_constraints;
	unsigned int n_equality;
	// basis function parameters
	bool modified_basis;
	// polynomial parameters
	bool poly_term;
	unsigned int n_poly_terms;
	// type of problem
	Parameter_Types::SolverType problem_type;
	//bool greedy; // greedy algorithm
	bool restricted_range; // restricted range constraints - bounded inequalities
	// initialization 
	basic_parameters() : n_interface(0), n_planar(0), n_inequality(0), n_tangent(0), n_constraints(0), n_equality(0),
		modified_basis(false), poly_term(true), n_poly_terms(4), problem_type(Parameter_Types::Linear),restricted_range(false){}
};

//Wrapper functions for external use
SURFE_LIB_EXPORT void* Create_ModelParameters_Instance();
SURFE_LIB_EXPORT void Release_ModelParameters_Instance(void* mpInstance);

#endif