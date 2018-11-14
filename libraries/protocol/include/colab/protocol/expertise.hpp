#pragma once
#include <colab/protocol/types.hpp>
#include <colab/protocol/config.hpp>

namespace colab { namespace protocol {	

	//Science Technology Engineering Mathematics
	typedef uint32_t expertise_category;
	static const expertise_category expctgry_unknown     = (0);
	static const expertise_category expctgry_science     = (1);
	static const expertise_category expctgry_technology  = (2);
	static const expertise_category expctgry_engineering = (3);
	static const expertise_category expctgry_mathematics = (4);
	class expertise
	{
	private:	
		static void set_expertise_category_str_map();

	public:

		expertise( expertise_category _c = expctgry_unknown, uint32_t _r = 1 ) : category(_c), level(_r){}

		expertise_category category;
		uint32_t level;

		static expertise_category category_from_str(const std::string& str);
		std::string category_str()const;

		static expertise from_string( const std::string& from );
		std::string       to_string()const;
	};
   
} } // colab::protocol

namespace fc {

    inline void to_variant( const colab::protocol::expertise& var,  fc::variant& vo ) { vo = var.to_string(); }
    inline void from_variant( const fc::variant& var,  colab::protocol::expertise& vo ) { vo = colab::protocol::expertise::from_string( var.as_string() ); }
}

//FC_REFLECT_ENUM( colab::protocol::expertise_category,  )
FC_REFLECT( colab::protocol::expertise, (category)(level) )