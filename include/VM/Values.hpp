#pragma once

#include "Allocator.hpp"
#include "Error.hpp"

namespace sc
{

enum class Values
{
	SIMPLE,
	INSTRUCTION,
};
class Value : public IAllocated
{
	ModuleLoc loc;
	Values valty;
	StringMap<String> attrs;

public:
	Value(ModuleLoc loc, Values valty);
	virtual ~Value();

	virtual String toString() const = 0;

#define isValueX(X, ENUMVAL) \
	inline bool is##X() { return valty == Values::ENUMVAL; }
	isValueX(Simple, SIMPLE);

	inline const ModuleLoc &getLoc() const { return loc; }

	inline bool hasAttribute(StringRef name) const { return attrs.find(name) != attrs.end(); }
	inline void addAttribute(StringRef name, StringRef val = "") { attrs[String(name)] = val; }
	inline void setAttributes(const StringMap<String> &_attrs) { attrs = _attrs; }
	inline void setAttributes(StringMap<String> &&_attrs)
	{
		using namespace std;
		swap(attrs, _attrs);
	}
	StringRef getAttributeValue(StringRef name) const;
	String attributesToString(StringRef prefix = "", StringRef suffix = "") const;
};

template<typename T> T *as(Value *data) { return static_cast<T *>(data); }

enum class SimpleValues
{
	INT,
	FLT,
	STR,
	CHAR,
	IDEN,
};
class SimpleValue : public Value
{
	SimpleValues simplevalty;
	Variant<String, int64_t, long double> data;

public:
	SimpleValue(ModuleLoc loc, SimpleValues simplevalty, char data);
	SimpleValue(ModuleLoc loc, SimpleValues simplevalty, int64_t data);
	SimpleValue(ModuleLoc loc, SimpleValues simplevalty, long double data);
	SimpleValue(ModuleLoc loc, SimpleValues simplevalty, StringRef data);
	~SimpleValue();

	static SimpleValue *create(Allocator &allocator, ModuleLoc loc, SimpleValues simplevalty,
				   char data);
	static SimpleValue *create(Allocator &allocator, ModuleLoc loc, SimpleValues simplevalty,
				   int64_t data);
	static SimpleValue *create(Allocator &allocator, ModuleLoc loc, SimpleValues simplevalty,
				   long double data);
	static SimpleValue *create(Allocator &allocator, ModuleLoc loc, SimpleValues simplevalty,
				   StringRef data);

	String toString() const override;

#define isSimpleValueX(X, ENUMVAL) \
	inline bool is##X() { return simplevalty == SimpleValues::ENUMVAL; }
	isSimpleValueX(Int, INT);
	isSimpleValueX(Flt, FLT);
	isSimpleValueX(Char, CHAR);
	isSimpleValueX(Str, STR);
	isSimpleValueX(Iden, IDEN);

	inline SimpleValues getType() { return simplevalty; }

	inline StringRef getDataStr() const { return std::get<String>(data); }
	inline int64_t getDataInt() const { return std::get<int64_t>(data); }
	inline long double getDataFlt() const { return std::get<long double>(data); }
};

} // namespace sc