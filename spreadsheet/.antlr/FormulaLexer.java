// Generated from /home/nikolai/projects/practicum/cpp-spreadsheet/spreadsheet/Formula.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue", "this-escape"})
public class FormulaLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, NUMBER=3, ADD=4, SUB=5, MUL=6, DIV=7, CELL=8, WS=9;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "INT", "UINT", "EXPONENT", "NUMBER", "ADD", "SUB", "MUL", 
			"DIV", "CELL", "WS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'('", "')'", null, "'+'", "'-'", "'*'", "'/'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, "NUMBER", "ADD", "SUB", "MUL", "DIV", "CELL", "WS"
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


	public FormulaLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Formula.g4"; }

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
		"\u0004\u0000\tQ\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002\u0001"+
		"\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004"+
		"\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007"+
		"\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b"+
		"\u0007\u000b\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0002"+
		"\u0003\u0002\u001f\b\u0002\u0001\u0002\u0001\u0002\u0001\u0003\u0004\u0003"+
		"$\b\u0003\u000b\u0003\f\u0003%\u0001\u0004\u0001\u0004\u0001\u0004\u0001"+
		"\u0005\u0001\u0005\u0003\u0005-\b\u0005\u0001\u0005\u0003\u00050\b\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0003\u00055\b\u0005\u0003\u0005"+
		"7\b\u0005\u0001\u0006\u0001\u0006\u0001\u0007\u0001\u0007\u0001\b\u0001"+
		"\b\u0001\t\u0001\t\u0001\n\u0004\nB\b\n\u000b\n\f\nC\u0001\n\u0004\nG"+
		"\b\n\u000b\n\f\nH\u0001\u000b\u0004\u000bL\b\u000b\u000b\u000b\f\u000b"+
		"M\u0001\u000b\u0001\u000b\u0000\u0000\f\u0001\u0001\u0003\u0002\u0005"+
		"\u0000\u0007\u0000\t\u0000\u000b\u0003\r\u0004\u000f\u0005\u0011\u0006"+
		"\u0013\u0007\u0015\b\u0017\t\u0001\u0000\u0005\u0002\u0000++--\u0001\u0000"+
		"09\u0002\u0000EEee\u0001\u0000AZ\u0003\u0000\t\n\r\r  V\u0000\u0001\u0001"+
		"\u0000\u0000\u0000\u0000\u0003\u0001\u0000\u0000\u0000\u0000\u000b\u0001"+
		"\u0000\u0000\u0000\u0000\r\u0001\u0000\u0000\u0000\u0000\u000f\u0001\u0000"+
		"\u0000\u0000\u0000\u0011\u0001\u0000\u0000\u0000\u0000\u0013\u0001\u0000"+
		"\u0000\u0000\u0000\u0015\u0001\u0000\u0000\u0000\u0000\u0017\u0001\u0000"+
		"\u0000\u0000\u0001\u0019\u0001\u0000\u0000\u0000\u0003\u001b\u0001\u0000"+
		"\u0000\u0000\u0005\u001e\u0001\u0000\u0000\u0000\u0007#\u0001\u0000\u0000"+
		"\u0000\t\'\u0001\u0000\u0000\u0000\u000b6\u0001\u0000\u0000\u0000\r8\u0001"+
		"\u0000\u0000\u0000\u000f:\u0001\u0000\u0000\u0000\u0011<\u0001\u0000\u0000"+
		"\u0000\u0013>\u0001\u0000\u0000\u0000\u0015A\u0001\u0000\u0000\u0000\u0017"+
		"K\u0001\u0000\u0000\u0000\u0019\u001a\u0005(\u0000\u0000\u001a\u0002\u0001"+
		"\u0000\u0000\u0000\u001b\u001c\u0005)\u0000\u0000\u001c\u0004\u0001\u0000"+
		"\u0000\u0000\u001d\u001f\u0007\u0000\u0000\u0000\u001e\u001d\u0001\u0000"+
		"\u0000\u0000\u001e\u001f\u0001\u0000\u0000\u0000\u001f \u0001\u0000\u0000"+
		"\u0000 !\u0003\u0007\u0003\u0000!\u0006\u0001\u0000\u0000\u0000\"$\u0007"+
		"\u0001\u0000\u0000#\"\u0001\u0000\u0000\u0000$%\u0001\u0000\u0000\u0000"+
		"%#\u0001\u0000\u0000\u0000%&\u0001\u0000\u0000\u0000&\b\u0001\u0000\u0000"+
		"\u0000\'(\u0007\u0002\u0000\u0000()\u0003\u0005\u0002\u0000)\n\u0001\u0000"+
		"\u0000\u0000*,\u0003\u0007\u0003\u0000+-\u0003\t\u0004\u0000,+\u0001\u0000"+
		"\u0000\u0000,-\u0001\u0000\u0000\u0000-7\u0001\u0000\u0000\u0000.0\u0003"+
		"\u0007\u0003\u0000/.\u0001\u0000\u0000\u0000/0\u0001\u0000\u0000\u0000"+
		"01\u0001\u0000\u0000\u000012\u0005.\u0000\u000024\u0003\u0007\u0003\u0000"+
		"35\u0003\t\u0004\u000043\u0001\u0000\u0000\u000045\u0001\u0000\u0000\u0000"+
		"57\u0001\u0000\u0000\u00006*\u0001\u0000\u0000\u00006/\u0001\u0000\u0000"+
		"\u00007\f\u0001\u0000\u0000\u000089\u0005+\u0000\u00009\u000e\u0001\u0000"+
		"\u0000\u0000:;\u0005-\u0000\u0000;\u0010\u0001\u0000\u0000\u0000<=\u0005"+
		"*\u0000\u0000=\u0012\u0001\u0000\u0000\u0000>?\u0005/\u0000\u0000?\u0014"+
		"\u0001\u0000\u0000\u0000@B\u0007\u0003\u0000\u0000A@\u0001\u0000\u0000"+
		"\u0000BC\u0001\u0000\u0000\u0000CA\u0001\u0000\u0000\u0000CD\u0001\u0000"+
		"\u0000\u0000DF\u0001\u0000\u0000\u0000EG\u0007\u0001\u0000\u0000FE\u0001"+
		"\u0000\u0000\u0000GH\u0001\u0000\u0000\u0000HF\u0001\u0000\u0000\u0000"+
		"HI\u0001\u0000\u0000\u0000I\u0016\u0001\u0000\u0000\u0000JL\u0007\u0004"+
		"\u0000\u0000KJ\u0001\u0000\u0000\u0000LM\u0001\u0000\u0000\u0000MK\u0001"+
		"\u0000\u0000\u0000MN\u0001\u0000\u0000\u0000NO\u0001\u0000\u0000\u0000"+
		"OP\u0006\u000b\u0000\u0000P\u0018\u0001\u0000\u0000\u0000\n\u0000\u001e"+
		"%,/46CHM\u0001\u0006\u0000\u0000";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}