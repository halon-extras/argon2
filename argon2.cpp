#include <HalonMTA.h>
#include <stdlib.h>
#include <argon2.h>

HALON_EXPORT
int Halon_version()
{
	return HALONMTA_PLUGIN_VERSION;
}

void _argon_verify(HalonHSLContext* hhc, HalonHSLArguments* args, HalonHSLValue* ret, argon2_type type)
{
	HalonHSLValue* a;

	char* encoded = nullptr;
	a = HalonMTA_hsl_argument_get(args, 0);
	if (a && HalonMTA_hsl_value_type(a) == HALONMTA_HSL_TYPE_STRING)
		HalonMTA_hsl_value_get(a, HALONMTA_HSL_TYPE_STRING, &encoded, nullptr);
	else
	{
		HalonHSLValue* x = HalonMTA_hsl_throw(hhc);
		HalonMTA_hsl_value_set(x, HALONMTA_HSL_TYPE_EXCEPTION, "Invalid or missing encoded parameter", 0);
		return;
	}

	char* pwd = nullptr;
	size_t pwdlen = 0;
	a = HalonMTA_hsl_argument_get(args, 1);
	if (a && HalonMTA_hsl_value_type(a) == HALONMTA_HSL_TYPE_STRING)
		HalonMTA_hsl_value_get(a, HALONMTA_HSL_TYPE_STRING, &pwd, &pwdlen);
	else
	{
		HalonHSLValue* x = HalonMTA_hsl_throw(hhc);
		HalonMTA_hsl_value_set(x, HALONMTA_HSL_TYPE_EXCEPTION, "Invalid or missing pwd parameter", 0);
		return;
	}

	bool ret_ = (argon2_verify(encoded, pwd, pwdlen, type) == ARGON2_OK);
	HalonMTA_hsl_value_set(ret, HALONMTA_HSL_TYPE_BOOLEAN, &ret_, 0);
}

void _argon2d_verify(HalonHSLContext* hhc, HalonHSLArguments* args, HalonHSLValue* ret)
{
	_argon_verify(hhc, args, ret, Argon2_d);
}

void _argon2i_verify(HalonHSLContext* hhc, HalonHSLArguments* args, HalonHSLValue* ret)
{
	_argon_verify(hhc, args, ret, Argon2_i);
}

void _argon2id_verify(HalonHSLContext* hhc, HalonHSLArguments* args, HalonHSLValue* ret)
{
	_argon_verify(hhc, args, ret, Argon2_id);
}

HALON_EXPORT
bool Halon_hsl_register(HalonHSLRegisterContext* ptr)
{
	HalonMTA_hsl_module_register_function(ptr, "argon2d_verify", &_argon2d_verify);
	HalonMTA_hsl_module_register_function(ptr, "argon2i_verify", &_argon2i_verify);
	HalonMTA_hsl_module_register_function(ptr, "argon2id_verify", &_argon2id_verify);
	return true;
}
