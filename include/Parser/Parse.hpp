/*
	MIT License

	Copyright (c) 2021 Scribe Language Repositories

	Permission is hereby granted, free of charge, to any person obtaining a
	copy of this software and associated documentation files (the "Software"), to
	deal in the Software without restriction, including without limitation the
	rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
	sell copies of the Software, and to permit persons to whom the Software is
	furnished to do so.
*/

#ifndef PARSER_PARSE_HPP
#define PARSER_PARSE_HPP

#include "ParseHelper.hpp"
#include "Stmts.hpp"

namespace sc
{
enum class Occurs
{
	YES,
	NO,
	MAYBE
};
class Parsing
{
	ErrMgr &err;
	Context &ctx;

public:
	Parsing(ErrMgr &err, Context &ctx);

	// on successful parse, returns true, and tree is allocated
	// if with_brace is true, it will attempt to find the beginning and ending brace for each
	// block
	bool parse_block(ParseHelper &p, StmtBlock *&tree, const bool &with_brace = true);

	bool parse_type(ParseHelper &p, StmtType *&type);
	bool parse_simple(ParseHelper &p, Stmt *&data);

	bool parse_expr(ParseHelper &p, Stmt *&expr, const bool &disable_brace_after_iden);
	bool parse_expr_17(ParseHelper &p, Stmt *&expr, const bool &disable_brace_after_iden);
	bool parse_expr_16(ParseHelper &p, Stmt *&expr, const bool &disable_brace_after_iden);
	bool parse_expr_15(ParseHelper &p, Stmt *&expr, const bool &disable_brace_after_iden);
	bool parse_expr_14(ParseHelper &p, Stmt *&expr, const bool &disable_brace_after_iden);
	bool parse_expr_13(ParseHelper &p, Stmt *&expr, const bool &disable_brace_after_iden);
	bool parse_expr_12(ParseHelper &p, Stmt *&expr, const bool &disable_brace_after_iden);
	bool parse_expr_11(ParseHelper &p, Stmt *&expr, const bool &disable_brace_after_iden);
	bool parse_expr_10(ParseHelper &p, Stmt *&expr, const bool &disable_brace_after_iden);
	bool parse_expr_09(ParseHelper &p, Stmt *&expr, const bool &disable_brace_after_iden);
	bool parse_expr_08(ParseHelper &p, Stmt *&expr, const bool &disable_brace_after_iden);
	bool parse_expr_07(ParseHelper &p, Stmt *&expr, const bool &disable_brace_after_iden);
	bool parse_expr_06(ParseHelper &p, Stmt *&expr, const bool &disable_brace_after_iden);
	bool parse_expr_05(ParseHelper &p, Stmt *&expr, const bool &disable_brace_after_iden);
	bool parse_expr_04(ParseHelper &p, Stmt *&expr, const bool &disable_brace_after_iden);
	bool parse_expr_03(ParseHelper &p, Stmt *&expr, const bool &disable_brace_after_iden);
	bool parse_expr_02(ParseHelper &p, Stmt *&expr, const bool &disable_brace_after_iden);
	bool parse_expr_01(ParseHelper &p, Stmt *&expr, const bool &disable_brace_after_iden);

	bool parse_var(ParseHelper &p, StmtVar *&var, const Occurs &intype, const Occurs &otype,
		       const Occurs &oval);

	bool parse_fnsig(ParseHelper &p, Stmt *&fsig);
	bool parse_fndef(ParseHelper &p, Stmt *&fndef);

	bool parse_header(ParseHelper &p, StmtHeader *&header);
	bool parse_lib(ParseHelper &p, StmtLib *&lib);
	bool parse_extern(ParseHelper &p, Stmt *&ext);

	bool parse_enum(ParseHelper &p, Stmt *&ed);
	bool parse_struct(ParseHelper &p, Stmt *&sd);

	bool parse_vardecl(ParseHelper &p, Stmt *&vd); // combines VAR_DECL_BASE and VAR_DECL

	bool parse_conds(ParseHelper &p, Stmt *&conds);
	bool parse_forin(ParseHelper &p, Stmt *&fin);
	bool parse_for(ParseHelper &p, Stmt *&f);
	bool parse_while(ParseHelper &p, Stmt *&w);
	bool parse_ret(ParseHelper &p, Stmt *&ret);
	bool parse_continue(ParseHelper &p, Stmt *&cont);
	bool parse_break(ParseHelper &p, Stmt *&brk);
	bool parse_defer(ParseHelper &p, Stmt *&defer);
};
} // namespace sc

#endif // PARSER_PARSE_HPP