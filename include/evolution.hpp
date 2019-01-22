#ifndef _EVOULUTION_H_
#define _EVOULUTION_H_

#include "field.hpp"


class LeapFrog
{
	private:
		int _precision;
		int _num_fields;
        int _num_threads;
		int _output_step;
		double _dt;
		double _a, _da, _dda;

		void evol_fields                 ( double** f, double** df, double h );
        void evol_field_derivs           ( double** f, double** df, Field* field, double h );
        void evol_field_derivs_expansion ( double** f, double** df, Field* field, double h );

		void evol_scale        ( Field* field, double** f, double h );
		void evol_scale_derivs ( double h ){ _da += _dda * h*_dt; }
		
	public:
		LeapFrog ( int precision, int num_fields, int num_threads, int output_step, double dt );

        void evolution           ( Field* field, double** f, double** df );
		void evolution_expansion ( Field* field, double** f, double** df, double t );

		double a()  { return _a; }
		double da() { return _da; }
};


#endif