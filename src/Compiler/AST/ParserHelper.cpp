#include "AST/ParseHelper.hpp"

namespace sc::ast
{
ParseHelper::ParseHelper(Vector<lex::Lexeme> &toks, size_t begin)
	: toks(toks), invalid(), eof(ModuleLoc(), lex::FEOF), idx(begin)
{}

lex::Lexeme &ParseHelper::peek(int offset)
{
	if(offset < 0 && idx < (-offset)) return eof;
	if(idx + offset >= toks.size()) return eof;
	return toks[idx + offset];
}

lex::TokType ParseHelper::peekt(int offset) const
{
	if(offset < 0 && idx < (-offset)) return eof.getType();
	if(idx + offset >= toks.size()) return eof.getType();
	return toks[idx + offset].getType();
}

lex::Lexeme &ParseHelper::next()
{
	++idx;
	if(idx >= toks.size()) return eof;
	return toks[idx];
}

lex::TokType ParseHelper::nextt()
{
	++idx;
	if(idx >= toks.size()) return eof.getType();
	return toks[idx].getType();
}

lex::Lexeme &ParseHelper::prev()
{
	if(idx == 0) return invalid;
	--idx;
	return toks[idx];
}

lex::TokType ParseHelper::prevt()
{
	if(idx == 0) return invalid.getType();
	--idx;
	return toks[idx].getType();
}

const lex::Lexeme *ParseHelper::at(size_t idx) const
{
	if(idx >= toks.size()) return &invalid;
	return &toks[idx];
}
} // namespace sc::ast