
// Generated from Formula.g4 by ANTLR 4.13.1


#include "FormulaListener.h"

#include "FormulaParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct FormulaParserStaticData final {
  FormulaParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  FormulaParserStaticData(const FormulaParserStaticData&) = delete;
  FormulaParserStaticData(FormulaParserStaticData&&) = delete;
  FormulaParserStaticData& operator=(const FormulaParserStaticData&) = delete;
  FormulaParserStaticData& operator=(FormulaParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag formulaParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
FormulaParserStaticData *formulaParserStaticData = nullptr;

void formulaParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (formulaParserStaticData != nullptr) {
    return;
  }
#else
  assert(formulaParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<FormulaParserStaticData>(
    std::vector<std::string>{
      "main", "expr"
    },
    std::vector<std::string>{
      "", "'('", "')'", "", "'+'", "'-'", "'*'", "'/'"
    },
    std::vector<std::string>{
      "", "", "", "NUMBER", "ADD", "SUB", "MUL", "DIV", "CELL", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,9,30,2,0,7,0,2,1,7,1,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,3,1,17,8,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,25,8,1,10,1,12,1,28,9,1,1,
  	1,0,1,2,2,0,2,0,2,1,0,4,5,1,0,6,7,32,0,4,1,0,0,0,2,16,1,0,0,0,4,5,3,2,
  	1,0,5,6,5,0,0,1,6,1,1,0,0,0,7,8,6,1,-1,0,8,9,5,1,0,0,9,10,3,2,1,0,10,
  	11,5,2,0,0,11,17,1,0,0,0,12,13,7,0,0,0,13,17,3,2,1,5,14,17,5,8,0,0,15,
  	17,5,3,0,0,16,7,1,0,0,0,16,12,1,0,0,0,16,14,1,0,0,0,16,15,1,0,0,0,17,
  	26,1,0,0,0,18,19,10,4,0,0,19,20,7,1,0,0,20,25,3,2,1,5,21,22,10,3,0,0,
  	22,23,7,0,0,0,23,25,3,2,1,4,24,18,1,0,0,0,24,21,1,0,0,0,25,28,1,0,0,0,
  	26,24,1,0,0,0,26,27,1,0,0,0,27,3,1,0,0,0,28,26,1,0,0,0,3,16,24,26
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  formulaParserStaticData = staticData.release();
}

}

FormulaParser::FormulaParser(TokenStream *input) : FormulaParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

FormulaParser::FormulaParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  FormulaParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *formulaParserStaticData->atn, formulaParserStaticData->decisionToDFA, formulaParserStaticData->sharedContextCache, options);
}

FormulaParser::~FormulaParser() {
  delete _interpreter;
}

const atn::ATN& FormulaParser::getATN() const {
  return *formulaParserStaticData->atn;
}

std::string FormulaParser::getGrammarFileName() const {
  return "Formula.g4";
}

const std::vector<std::string>& FormulaParser::getRuleNames() const {
  return formulaParserStaticData->ruleNames;
}

const dfa::Vocabulary& FormulaParser::getVocabulary() const {
  return formulaParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView FormulaParser::getSerializedATN() const {
  return formulaParserStaticData->serializedATN;
}


//----------------- MainContext ------------------------------------------------------------------

FormulaParser::MainContext::MainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FormulaParser::ExprContext* FormulaParser::MainContext::expr() {
  return getRuleContext<FormulaParser::ExprContext>(0);
}

tree::TerminalNode* FormulaParser::MainContext::EOF() {
  return getToken(FormulaParser::EOF, 0);
}


size_t FormulaParser::MainContext::getRuleIndex() const {
  return FormulaParser::RuleMain;
}

void FormulaParser::MainContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMain(this);
}

void FormulaParser::MainContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMain(this);
}

FormulaParser::MainContext* FormulaParser::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 0, FormulaParser::RuleMain);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(4);
    expr(0);
    setState(5);
    match(FormulaParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

FormulaParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FormulaParser::ExprContext::getRuleIndex() const {
  return FormulaParser::RuleExpr;
}

void FormulaParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UnaryOpContext ------------------------------------------------------------------

FormulaParser::ExprContext* FormulaParser::UnaryOpContext::expr() {
  return getRuleContext<FormulaParser::ExprContext>(0);
}

tree::TerminalNode* FormulaParser::UnaryOpContext::ADD() {
  return getToken(FormulaParser::ADD, 0);
}

tree::TerminalNode* FormulaParser::UnaryOpContext::SUB() {
  return getToken(FormulaParser::SUB, 0);
}

FormulaParser::UnaryOpContext::UnaryOpContext(ExprContext *ctx) { copyFrom(ctx); }

void FormulaParser::UnaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOp(this);
}
void FormulaParser::UnaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOp(this);
}
//----------------- ParensContext ------------------------------------------------------------------

FormulaParser::ExprContext* FormulaParser::ParensContext::expr() {
  return getRuleContext<FormulaParser::ExprContext>(0);
}

FormulaParser::ParensContext::ParensContext(ExprContext *ctx) { copyFrom(ctx); }

void FormulaParser::ParensContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParens(this);
}
void FormulaParser::ParensContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParens(this);
}
//----------------- LiteralContext ------------------------------------------------------------------

tree::TerminalNode* FormulaParser::LiteralContext::NUMBER() {
  return getToken(FormulaParser::NUMBER, 0);
}

FormulaParser::LiteralContext::LiteralContext(ExprContext *ctx) { copyFrom(ctx); }

void FormulaParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}
void FormulaParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}
//----------------- CellContext ------------------------------------------------------------------

tree::TerminalNode* FormulaParser::CellContext::CELL() {
  return getToken(FormulaParser::CELL, 0);
}

FormulaParser::CellContext::CellContext(ExprContext *ctx) { copyFrom(ctx); }

void FormulaParser::CellContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCell(this);
}
void FormulaParser::CellContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCell(this);
}
//----------------- BinaryOpContext ------------------------------------------------------------------

std::vector<FormulaParser::ExprContext *> FormulaParser::BinaryOpContext::expr() {
  return getRuleContexts<FormulaParser::ExprContext>();
}

FormulaParser::ExprContext* FormulaParser::BinaryOpContext::expr(size_t i) {
  return getRuleContext<FormulaParser::ExprContext>(i);
}

tree::TerminalNode* FormulaParser::BinaryOpContext::MUL() {
  return getToken(FormulaParser::MUL, 0);
}

tree::TerminalNode* FormulaParser::BinaryOpContext::DIV() {
  return getToken(FormulaParser::DIV, 0);
}

tree::TerminalNode* FormulaParser::BinaryOpContext::ADD() {
  return getToken(FormulaParser::ADD, 0);
}

tree::TerminalNode* FormulaParser::BinaryOpContext::SUB() {
  return getToken(FormulaParser::SUB, 0);
}

FormulaParser::BinaryOpContext::BinaryOpContext(ExprContext *ctx) { copyFrom(ctx); }

void FormulaParser::BinaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryOp(this);
}
void FormulaParser::BinaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryOp(this);
}

FormulaParser::ExprContext* FormulaParser::expr() {
   return expr(0);
}

FormulaParser::ExprContext* FormulaParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  FormulaParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  FormulaParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, FormulaParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(16);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FormulaParser::T__0: {
        _localctx = _tracker.createInstance<ParensContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(8);
        match(FormulaParser::T__0);
        setState(9);
        expr(0);
        setState(10);
        match(FormulaParser::T__1);
        break;
      }

      case FormulaParser::ADD:
      case FormulaParser::SUB: {
        _localctx = _tracker.createInstance<UnaryOpContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(12);
        _la = _input->LA(1);
        if (!(_la == FormulaParser::ADD

        || _la == FormulaParser::SUB)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(13);
        expr(5);
        break;
      }

      case FormulaParser::CELL: {
        _localctx = _tracker.createInstance<CellContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(14);
        match(FormulaParser::CELL);
        break;
      }

      case FormulaParser::NUMBER: {
        _localctx = _tracker.createInstance<LiteralContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(15);
        match(FormulaParser::NUMBER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(26);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(24);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(18);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(19);
          _la = _input->LA(1);
          if (!(_la == FormulaParser::MUL

          || _la == FormulaParser::DIV)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(20);
          expr(5);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryOpContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(21);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(22);
          _la = _input->LA(1);
          if (!(_la == FormulaParser::ADD

          || _la == FormulaParser::SUB)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(23);
          expr(4);
          break;
        }

        default:
          break;
        } 
      }
      setState(28);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool FormulaParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool FormulaParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);
    case 1: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

void FormulaParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  formulaParserInitialize();
#else
  ::antlr4::internal::call_once(formulaParserOnceFlag, formulaParserInitialize);
#endif
}
