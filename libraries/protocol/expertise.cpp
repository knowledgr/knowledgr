#include <colab/protocol/expertise.hpp>
#include <boost/rational.hpp>
#include <boost/multiprecision/cpp_int.hpp>

/*


*/

namespace colab { namespace protocol {

	static std::map<protocol::expertise_category, std::string> category_str_map;
	void expertise::set_expertise_category_str_map() {
		category_str_map[expctgry_unknown] = "unknown";
		category_str_map[expctgry_science] = "science";
		category_str_map[expctgry_technology] = "technology";
		category_str_map[expctgry_engineering] = "engineering";
		category_str_map[expctgry_mathematics] = "mathematics";
	}

	std::string expertise::category_str()const
	{
		if (category_str_map.size() <= 0) {
			set_expertise_category_str_map();
		}

		if ( category >= expctgry_unknown && category <= expctgry_mathematics ) return category_str_map[category];
		return "unknown";
	}

	expertise_category expertise::category_from_str(const std::string& str)
	{
		if (category_str_map.size() <= 0) {
			set_expertise_category_str_map();
		}

		std::string _str = fc::to_lower(fc::trim(str));
		for (map<expertise_category, std::string>::const_iterator i1 = category_str_map.begin(); i1 != category_str_map.end(); i1 ++) {
			if ((*i1).second == _str) {
				return (*i1).first;
			}
		}
		return expctgry_unknown;
	}

	std::string expertise::to_string()const
	{
		std::string result = category_str();
		char s[100];
		result += " : ";
		sprintf(s, "%d", level);
		result += s;
		return result;
	}
	expertise expertise::from_string( const std::string& from )
	{
		try
		{
			string s = fc::trim( from );
			auto dot_pos = s.find( ":" );
			expertise result;
			if( dot_pos != std::string::npos )
			{
				auto cpart = s.substr( 0, dot_pos );
				auto rpart = s.substr( dot_pos + 1, s.length() - dot_pos- 1 );
				result.category = expertise::category_from_str(cpart);
				
				sscanf(rpart.c_str(), "%d", &result.level);
			}

			return result;
		}
		FC_CAPTURE_AND_RETHROW( (from) )
	}

} } // colab::protocol
