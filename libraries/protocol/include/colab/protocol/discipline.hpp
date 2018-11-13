#pragma once
#include <colab/protocol/types.hpp>
#include <colab/protocol/config.hpp>

namespace colab { namespace protocol {	

	//Science Technology Engineering Mathematics
	typedef uint32_t discipline_category;
	static const discipline_category dc_unknown     = (0);
	static const discipline_category dc_science     = (1);
	static const discipline_category dc_technology  = (2);
	static const discipline_category dc_engineering = (3);
	static const discipline_category dc_mathematics = (4);
	class discipline
	{
	private:	
		static void set_discipline_category_str_map();

	public:

		discipline( discipline_category _c = dc_unknown, uint32_t _r = 1 ) : category(_c), level(_r){}

		discipline_category category;
		uint32_t level;

		static discipline_category category_from_str(const std::string& str);
		std::string category_str()const;

		static discipline from_string( const std::string& from );
		std::string       to_string()const;
	};
   
} } // colab::protocol

namespace fc {

    inline void to_variant( const colab::protocol::discipline& var,  fc::variant& vo ) { vo = var.to_string(); }
    inline void from_variant( const fc::variant& var,  colab::protocol::discipline& vo ) { vo = colab::protocol::discipline::from_string( var.as_string() ); }
}

//FC_REFLECT_ENUM( colab::protocol::discipline_category,  )
FC_REFLECT( colab::protocol::discipline, (category)(level) )