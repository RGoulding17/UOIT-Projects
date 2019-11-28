// Generated from Paren.g4 by ANTLR 4.7.2
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link ParenParser}.
 */
public interface ParenListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link ParenParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr(ParenParser.ExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link ParenParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr(ParenParser.ExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link ParenParser#exprGroup}.
	 * @param ctx the parse tree
	 */
	void enterExprGroup(ParenParser.ExprGroupContext ctx);
	/**
	 * Exit a parse tree produced by {@link ParenParser#exprGroup}.
	 * @param ctx the parse tree
	 */
	void exitExprGroup(ParenParser.ExprGroupContext ctx);
	/**
	 * Enter a parse tree produced by {@link ParenParser#exprTree}.
	 * @param ctx the parse tree
	 */
	void enterExprTree(ParenParser.ExprTreeContext ctx);
	/**
	 * Exit a parse tree produced by {@link ParenParser#exprTree}.
	 * @param ctx the parse tree
	 */
	void exitExprTree(ParenParser.ExprTreeContext ctx);
}