// Generated from Expr.g4 by ANTLR 4.7.2
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class ExprLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.7.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, FACTOR=2, OPEN_PAREN=3, CLOSE_PAREN=4, OUTPUT=5, COMMENT=6, EQ=7, 
		PLUS=8, MINUS=9, MULT=10, DIV=11, POW=12, PERIOD=13, NEWLINE=14, WHITESPACE=15;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "FACTOR", "OPEN_PAREN", "CLOSE_PAREN", "OUTPUT", "COMMENT", "EQ", 
			"PLUS", "MINUS", "MULT", "DIV", "POW", "PERIOD", "NEWLINE", "WHITESPACE"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "':'", null, "'('", "')'", null, null, "'='", "'+'", "'-'", "'*'", 
			"'/'", "'^'", "'.'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, "FACTOR", "OPEN_PAREN", "CLOSE_PAREN", "OUTPUT", "COMMENT", 
			"EQ", "PLUS", "MINUS", "MULT", "DIV", "POW", "PERIOD", "NEWLINE", "WHITESPACE"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public ExprLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Expr.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\21\177\b\1\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\3\2\3\2\3\3\3\3\3"+
		"\3\3\3\5\3(\n\3\3\3\6\3+\n\3\r\3\16\3,\3\3\3\3\6\3\61\n\3\r\3\16\3\62"+
		"\5\3\65\n\3\3\3\5\38\n\3\3\4\3\4\3\5\3\5\3\6\3\6\6\6@\n\6\r\6\16\6A\3"+
		"\6\5\6E\n\6\6\6G\n\6\r\6\16\6H\3\6\3\6\3\7\3\7\3\7\3\7\6\7Q\n\7\r\7\16"+
		"\7R\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\5\7^\n\7\3\7\5\7a\n\7\6\7c\n\7"+
		"\r\7\16\7d\3\b\3\b\3\t\3\t\3\n\3\n\3\13\3\13\3\f\3\f\3\r\3\r\3\16\3\16"+
		"\3\17\3\17\3\17\3\17\3\20\6\20z\n\20\r\20\16\20{\3\20\3\20\2\2\21\3\3"+
		"\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33\17\35\20\37\21"+
		"\3\2\7\3\2\62;\4\2C\\c|\5\2\62;C\\c|\3\2\f\f\4\2\13\13\"\"\2\u0093\2\3"+
		"\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2"+
		"\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31"+
		"\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\3!\3\2\2\2\5\'\3\2\2\2"+
		"\79\3\2\2\2\t;\3\2\2\2\13=\3\2\2\2\rL\3\2\2\2\17f\3\2\2\2\21h\3\2\2\2"+
		"\23j\3\2\2\2\25l\3\2\2\2\27n\3\2\2\2\31p\3\2\2\2\33r\3\2\2\2\35t\3\2\2"+
		"\2\37y\3\2\2\2!\"\7<\2\2\"\4\3\2\2\2#$\7u\2\2$%\7k\2\2%&\7p\2\2&(\7*\2"+
		"\2\'#\3\2\2\2\'(\3\2\2\2(*\3\2\2\2)+\t\2\2\2*)\3\2\2\2+,\3\2\2\2,*\3\2"+
		"\2\2,-\3\2\2\2-\64\3\2\2\2.\60\13\2\2\2/\61\t\2\2\2\60/\3\2\2\2\61\62"+
		"\3\2\2\2\62\60\3\2\2\2\62\63\3\2\2\2\63\65\3\2\2\2\64.\3\2\2\2\64\65\3"+
		"\2\2\2\65\67\3\2\2\2\668\7+\2\2\67\66\3\2\2\2\678\3\2\2\28\6\3\2\2\29"+
		":\7*\2\2:\b\3\2\2\2;<\7+\2\2<\n\3\2\2\2=F\7$\2\2>@\t\3\2\2?>\3\2\2\2@"+
		"A\3\2\2\2A?\3\2\2\2AB\3\2\2\2BD\3\2\2\2CE\7\"\2\2DC\3\2\2\2DE\3\2\2\2"+
		"EG\3\2\2\2F?\3\2\2\2GH\3\2\2\2HF\3\2\2\2HI\3\2\2\2IJ\3\2\2\2JK\7$\2\2"+
		"K\f\3\2\2\2LM\7%\2\2MN\7\"\2\2Nb\3\2\2\2OQ\t\4\2\2PO\3\2\2\2QR\3\2\2\2"+
		"RP\3\2\2\2RS\3\2\2\2S^\3\2\2\2T^\5\33\16\2U^\5\17\b\2V^\5\21\t\2W^\5\23"+
		"\n\2X^\5\25\13\2Y^\5\27\f\2Z^\5\31\r\2[^\5\7\4\2\\^\5\t\5\2]P\3\2\2\2"+
		"]T\3\2\2\2]U\3\2\2\2]V\3\2\2\2]W\3\2\2\2]X\3\2\2\2]Y\3\2\2\2]Z\3\2\2\2"+
		"][\3\2\2\2]\\\3\2\2\2^`\3\2\2\2_a\7\"\2\2`_\3\2\2\2`a\3\2\2\2ac\3\2\2"+
		"\2b]\3\2\2\2cd\3\2\2\2db\3\2\2\2de\3\2\2\2e\16\3\2\2\2fg\7?\2\2g\20\3"+
		"\2\2\2hi\7-\2\2i\22\3\2\2\2jk\7/\2\2k\24\3\2\2\2lm\7,\2\2m\26\3\2\2\2"+
		"no\7\61\2\2o\30\3\2\2\2pq\7`\2\2q\32\3\2\2\2rs\7\60\2\2s\34\3\2\2\2tu"+
		"\t\5\2\2uv\3\2\2\2vw\b\17\2\2w\36\3\2\2\2xz\t\6\2\2yx\3\2\2\2z{\3\2\2"+
		"\2{y\3\2\2\2{|\3\2\2\2|}\3\2\2\2}~\b\20\2\2~ \3\2\2\2\20\2\',\62\64\67"+
		"ADHR]`d{\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}