#pragma once
#include <colab/protocol/types.hpp>
#include <colab/protocol/config.hpp>

namespace colab { namespace protocol {	

	typedef uint32_t expertise_category;

	static const expertise_category expctgry_unknown					= (0);
	static const expertise_category expctgry_logic						= (1);
	static const expertise_category expctgry_mathematics				= (2);
	static const expertise_category expctgry_astronomy_and_astrophysics	= (3);
	static const expertise_category expctgry_physics					= (4); 
	static const expertise_category expctgry_chemistry					= (5);
	static const expertise_category expctgry_life_sciences				= (6);
	static const expertise_category expctgry_earth_and_space_sciences	= (7);
	static const expertise_category expctgry_agricultural_sciences		= (8);
	static const expertise_category expctgry_medical_sciences			= (9);
	static const expertise_category expctgry_technological_sciences		= (10);
	static const expertise_category expctgry_anthropology				= (11);
	static const expertise_category expctgry_demographics				= (12);
	static const expertise_category expctgry_economic_sciences			= (13); 
	static const expertise_category expctgry_geography					= (14); 
	static const expertise_category expctgry_history 					= (15);
	static const expertise_category expctgry_juridical_sciences_and_law	= (16);
	static const expertise_category expctgry_linguistics				= (17);
	static const expertise_category expctgry_pedagogy					= (18);
	static const expertise_category expctgry_political_science			= (19);
	static const expertise_category expctgry_psychology					= (20);
	static const expertise_category expctgry_science_of_arts_and_letters= (21); 
	static const expertise_category expctgry_sociology					= (22);
	static const expertise_category expctgry_ethics						= (23);
	static const expertise_category expctgry_philosophy					= (24);

	class expertise
	{
	private:	
		static void set_expertise_category_str_map();

	public:

		expertise( expertise_category _c = expctgry_unknown, uint32_t _r = 1 ) : category(_c), level(_r){}

		expertise_category	category;
		uint32_t			level;

		static vector<protocol::expertise_category> category_array_from_string(const std::string& str);
		static expertise_category					category_from_string(const std::string& str);
		static std::string category_str(protocol::expertise_category _c);

		std::string category_str()const;

		static expertise	from_string( const std::string& from );
		std::string			to_string()const;
	};
   
} } // colab::protocol

namespace fc {

    inline void to_variant( const colab::protocol::expertise& var,  fc::variant& vo ) { vo = var.to_string(); }
    inline void from_variant( const fc::variant& var,  colab::protocol::expertise& vo ) { vo = colab::protocol::expertise::from_string( var.as_string() ); }
}

//FC_REFLECT_ENUM( colab::protocol::expertise_category,  )
FC_REFLECT( colab::protocol::expertise, (category)(level) )