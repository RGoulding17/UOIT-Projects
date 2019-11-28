// Generated from Expr.g4 by ANTLR 4.7.2
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link ExprParser}.
 */
public interface ExprListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link ExprParser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgram(ExprParser.ProgramContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgram(ExprParser.ProgramContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#stmt}.
	 * @param ctx the parse tree
	 */
	void enterStmt(ExprParser.StmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#stmt}.
	 * @param ctx the parse tree
	 */
	void exitStmt(ExprParser.StmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(ExprParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(ExprParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#precision}.
	 * @param ctx the parse tree
	 */
	void enterPrecision(ExprParser.PrecisionContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#precision}.
	 * @param ctx the parse tree
	 */
	void exitPrecision(ExprParser.PrecisionContext ctx);
	/**
	 * Enter a parse tree produced by {@link ExprParser#operator}.
	 * @param ctx the parse tree
	 */
	void enterOperator(ExprParser.OperatorContext ctx);
	/**
	 * Exit a parse tree produced by {@link ExprParser#operator}.
	 * @param ctx the parse tree
	 */
	void exitOperator(ExprParser.OperatorContext ctx);
}