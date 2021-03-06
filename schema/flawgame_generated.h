// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_FLAWGAME_FLAW_H_
#define FLATBUFFERS_GENERATED_FLAWGAME_FLAW_H_

#include "flatbuffers/flatbuffers.h"

namespace flaw {

struct PrevSpeed;

struct Aiprior;

struct Control;

struct Speed;

struct Wizard;
struct WizardT;

struct Extra;

struct Holes;

struct Game;
struct GameT;

enum Color {
  Color_BLUE = 0,
  Color_RED = 1,
  Color_PURPLE = 2,
  Color_BLACK = 3,
  Color_GREEN = 4,
  Color_BURN = 5,
  Color_GHOST = 6,
  Color_ORANGE = 7,
  Color_MIN = Color_BLUE,
  Color_MAX = Color_ORANGE
};

inline const char **EnumNamesColor() {
  static const char *names[] = {
    "BLUE",
    "RED",
    "PURPLE",
    "BLACK",
    "GREEN",
    "BURN",
    "GHOST",
    "ORANGE",
    nullptr
  };
  return names;
}

inline const char *EnumNameColor(Color e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesColor()[index];
}

MANUALLY_ALIGNED_STRUCT(4) PrevSpeed FLATBUFFERS_FINAL_CLASS {
 private:
  float x_;
  float y_;

 public:
  PrevSpeed() {
    memset(this, 0, sizeof(PrevSpeed));
  }
  PrevSpeed(const PrevSpeed &_o) {
    memcpy(this, &_o, sizeof(PrevSpeed));
  }
  PrevSpeed(float _x, float _y)
      : x_(flatbuffers::EndianScalar(_x)),
        y_(flatbuffers::EndianScalar(_y)) {
  }
  float x() const {
    return flatbuffers::EndianScalar(x_);
  }
  float y() const {
    return flatbuffers::EndianScalar(y_);
  }
};
STRUCT_END(PrevSpeed, 8);

MANUALLY_ALIGNED_STRUCT(4) Aiprior FLATBUFFERS_FINAL_CLASS {
 private:
  float x_;
  float y_;

 public:
  Aiprior() {
    memset(this, 0, sizeof(Aiprior));
  }
  Aiprior(const Aiprior &_o) {
    memcpy(this, &_o, sizeof(Aiprior));
  }
  Aiprior(float _x, float _y)
      : x_(flatbuffers::EndianScalar(_x)),
        y_(flatbuffers::EndianScalar(_y)) {
  }
  float x() const {
    return flatbuffers::EndianScalar(x_);
  }
  float y() const {
    return flatbuffers::EndianScalar(y_);
  }
};
STRUCT_END(Aiprior, 8);

MANUALLY_ALIGNED_STRUCT(4) Control FLATBUFFERS_FINAL_CLASS {
 private:
  int32_t x_;
  int32_t y_;
  uint8_t fire_;
  int8_t padding0__;  int16_t padding1__;

 public:
  Control() {
    memset(this, 0, sizeof(Control));
  }
  Control(const Control &_o) {
    memcpy(this, &_o, sizeof(Control));
  }
  Control(int32_t _x, int32_t _y, bool _fire)
      : x_(flatbuffers::EndianScalar(_x)),
        y_(flatbuffers::EndianScalar(_y)),
        fire_(flatbuffers::EndianScalar(static_cast<uint8_t>(_fire))),
        padding0__(0),
        padding1__(0) {
    (void)padding0__;    (void)padding1__;
  }
  int32_t x() const {
    return flatbuffers::EndianScalar(x_);
  }
  int32_t y() const {
    return flatbuffers::EndianScalar(y_);
  }
  bool fire() const {
    return flatbuffers::EndianScalar(fire_) != 0;
  }
};
STRUCT_END(Control, 12);

MANUALLY_ALIGNED_STRUCT(4) Speed FLATBUFFERS_FINAL_CLASS {
 private:
  float x_;
  float y_;

 public:
  Speed() {
    memset(this, 0, sizeof(Speed));
  }
  Speed(const Speed &_o) {
    memcpy(this, &_o, sizeof(Speed));
  }
  Speed(float _x, float _y)
      : x_(flatbuffers::EndianScalar(_x)),
        y_(flatbuffers::EndianScalar(_y)) {
  }
  float x() const {
    return flatbuffers::EndianScalar(x_);
  }
  float y() const {
    return flatbuffers::EndianScalar(y_);
  }
};
STRUCT_END(Speed, 8);

MANUALLY_ALIGNED_STRUCT(4) Extra FLATBUFFERS_FINAL_CLASS {
 private:
  int32_t x_;
  int32_t y_;
  uint8_t enabled_;
  uint8_t newgem_;
  uint8_t on_;
  uint8_t blitted_;

 public:
  Extra() {
    memset(this, 0, sizeof(Extra));
  }
  Extra(const Extra &_o) {
    memcpy(this, &_o, sizeof(Extra));
  }
  Extra(int32_t _x, int32_t _y, bool _enabled, bool _newgem, bool _on, bool _blitted)
      : x_(flatbuffers::EndianScalar(_x)),
        y_(flatbuffers::EndianScalar(_y)),
        enabled_(flatbuffers::EndianScalar(static_cast<uint8_t>(_enabled))),
        newgem_(flatbuffers::EndianScalar(static_cast<uint8_t>(_newgem))),
        on_(flatbuffers::EndianScalar(static_cast<uint8_t>(_on))),
        blitted_(flatbuffers::EndianScalar(static_cast<uint8_t>(_blitted))) {
  }
  int32_t x() const {
    return flatbuffers::EndianScalar(x_);
  }
  int32_t y() const {
    return flatbuffers::EndianScalar(y_);
  }
  bool enabled() const {
    return flatbuffers::EndianScalar(enabled_) != 0;
  }
  bool newgem() const {
    return flatbuffers::EndianScalar(newgem_) != 0;
  }
  bool on() const {
    return flatbuffers::EndianScalar(on_) != 0;
  }
  bool blitted() const {
    return flatbuffers::EndianScalar(blitted_) != 0;
  }
};
STRUCT_END(Extra, 12);

MANUALLY_ALIGNED_STRUCT(4) Holes FLATBUFFERS_FINAL_CLASS {
 private:
  float x_;
  float y_;
  float radius_;

 public:
  Holes() {
    memset(this, 0, sizeof(Holes));
  }
  Holes(const Holes &_o) {
    memcpy(this, &_o, sizeof(Holes));
  }
  Holes(float _x, float _y, float _radius)
      : x_(flatbuffers::EndianScalar(_x)),
        y_(flatbuffers::EndianScalar(_y)),
        radius_(flatbuffers::EndianScalar(_radius)) {
  }
  float x() const {
    return flatbuffers::EndianScalar(x_);
  }
  float y() const {
    return flatbuffers::EndianScalar(y_);
  }
  float radius() const {
    return flatbuffers::EndianScalar(radius_);
  }
};
STRUCT_END(Holes, 12);

struct WizardT : public flatbuffers::NativeTable {
  typedef Wizard TableType;
  Color color;
  bool shield;
  int32_t points;
  int32_t x;
  int32_t y;
  int32_t w;
  int32_t h;
  int32_t aidelay;
  int32_t reaction;
  int32_t gfxset;
  int32_t follows;
  bool skid;
  float yoffset;
  std::unique_ptr<Speed> speed;
  std::unique_ptr<PrevSpeed> prevspeed;
  std::unique_ptr<Aiprior> aiprior;
  std::unique_ptr<Control> control;
  double strategic_state;
  bool joystick;
  bool ai;
  int32_t keyboard;
  int32_t direction;
  int32_t frame;
  int32_t extra;
  int32_t status;
  int32_t idletime;
  int32_t timer;
  WizardT()
      : color(Color_BLUE),
        shield(false),
        points(0),
        x(0),
        y(0),
        w(0),
        h(0),
        aidelay(0),
        reaction(0),
        gfxset(0),
        follows(0),
        skid(false),
        yoffset(0.0f),
        strategic_state(0.0),
        joystick(false),
        ai(false),
        keyboard(0),
        direction(0),
        frame(0),
        extra(0),
        status(0),
        idletime(0),
        timer(0) {
  }
};

struct Wizard FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef WizardT NativeTableType;
  enum {
    VT_COLOR = 4,
    VT_SHIELD = 6,
    VT_POINTS = 8,
    VT_X = 10,
    VT_Y = 12,
    VT_W = 14,
    VT_H = 16,
    VT_AIDELAY = 18,
    VT_REACTION = 20,
    VT_GFXSET = 22,
    VT_FOLLOWS = 24,
    VT_SKID = 26,
    VT_YOFFSET = 28,
    VT_SPEED = 30,
    VT_PREVSPEED = 32,
    VT_AIPRIOR = 34,
    VT_CONTROL = 36,
    VT_STRATEGIC_STATE = 38,
    VT_JOYSTICK = 40,
    VT_AI = 42,
    VT_KEYBOARD = 44,
    VT_DIRECTION = 46,
    VT_FRAME = 48,
    VT_EXTRA = 50,
    VT_STATUS = 52,
    VT_IDLETIME = 54,
    VT_TIMER = 56
  };
  Color color() const {
    return static_cast<Color>(GetField<int8_t>(VT_COLOR, 0));
  }
  bool shield() const {
    return GetField<uint8_t>(VT_SHIELD, 0) != 0;
  }
  int32_t points() const {
    return GetField<int32_t>(VT_POINTS, 0);
  }
  int32_t x() const {
    return GetField<int32_t>(VT_X, 0);
  }
  int32_t y() const {
    return GetField<int32_t>(VT_Y, 0);
  }
  int32_t w() const {
    return GetField<int32_t>(VT_W, 0);
  }
  int32_t h() const {
    return GetField<int32_t>(VT_H, 0);
  }
  int32_t aidelay() const {
    return GetField<int32_t>(VT_AIDELAY, 0);
  }
  int32_t reaction() const {
    return GetField<int32_t>(VT_REACTION, 0);
  }
  int32_t gfxset() const {
    return GetField<int32_t>(VT_GFXSET, 0);
  }
  int32_t follows() const {
    return GetField<int32_t>(VT_FOLLOWS, 0);
  }
  bool skid() const {
    return GetField<uint8_t>(VT_SKID, 0) != 0;
  }
  float yoffset() const {
    return GetField<float>(VT_YOFFSET, 0.0f);
  }
  const Speed *speed() const {
    return GetStruct<const Speed *>(VT_SPEED);
  }
  const PrevSpeed *prevspeed() const {
    return GetStruct<const PrevSpeed *>(VT_PREVSPEED);
  }
  const Aiprior *aiprior() const {
    return GetStruct<const Aiprior *>(VT_AIPRIOR);
  }
  const Control *control() const {
    return GetStruct<const Control *>(VT_CONTROL);
  }
  double strategic_state() const {
    return GetField<double>(VT_STRATEGIC_STATE, 0.0);
  }
  bool joystick() const {
    return GetField<uint8_t>(VT_JOYSTICK, 0) != 0;
  }
  bool ai() const {
    return GetField<uint8_t>(VT_AI, 0) != 0;
  }
  int32_t keyboard() const {
    return GetField<int32_t>(VT_KEYBOARD, 0);
  }
  int32_t direction() const {
    return GetField<int32_t>(VT_DIRECTION, 0);
  }
  int32_t frame() const {
    return GetField<int32_t>(VT_FRAME, 0);
  }
  int32_t extra() const {
    return GetField<int32_t>(VT_EXTRA, 0);
  }
  int32_t status() const {
    return GetField<int32_t>(VT_STATUS, 0);
  }
  int32_t idletime() const {
    return GetField<int32_t>(VT_IDLETIME, 0);
  }
  int32_t timer() const {
    return GetField<int32_t>(VT_TIMER, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int8_t>(verifier, VT_COLOR) &&
           VerifyField<uint8_t>(verifier, VT_SHIELD) &&
           VerifyField<int32_t>(verifier, VT_POINTS) &&
           VerifyField<int32_t>(verifier, VT_X) &&
           VerifyField<int32_t>(verifier, VT_Y) &&
           VerifyField<int32_t>(verifier, VT_W) &&
           VerifyField<int32_t>(verifier, VT_H) &&
           VerifyField<int32_t>(verifier, VT_AIDELAY) &&
           VerifyField<int32_t>(verifier, VT_REACTION) &&
           VerifyField<int32_t>(verifier, VT_GFXSET) &&
           VerifyField<int32_t>(verifier, VT_FOLLOWS) &&
           VerifyField<uint8_t>(verifier, VT_SKID) &&
           VerifyField<float>(verifier, VT_YOFFSET) &&
           VerifyField<Speed>(verifier, VT_SPEED) &&
           VerifyField<PrevSpeed>(verifier, VT_PREVSPEED) &&
           VerifyField<Aiprior>(verifier, VT_AIPRIOR) &&
           VerifyField<Control>(verifier, VT_CONTROL) &&
           VerifyField<double>(verifier, VT_STRATEGIC_STATE) &&
           VerifyField<uint8_t>(verifier, VT_JOYSTICK) &&
           VerifyField<uint8_t>(verifier, VT_AI) &&
           VerifyField<int32_t>(verifier, VT_KEYBOARD) &&
           VerifyField<int32_t>(verifier, VT_DIRECTION) &&
           VerifyField<int32_t>(verifier, VT_FRAME) &&
           VerifyField<int32_t>(verifier, VT_EXTRA) &&
           VerifyField<int32_t>(verifier, VT_STATUS) &&
           VerifyField<int32_t>(verifier, VT_IDLETIME) &&
           VerifyField<int32_t>(verifier, VT_TIMER) &&
           verifier.EndTable();
  }
  WizardT *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(WizardT *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<Wizard> Pack(flatbuffers::FlatBufferBuilder &_fbb, const WizardT* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct WizardBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_color(Color color) {
    fbb_.AddElement<int8_t>(Wizard::VT_COLOR, static_cast<int8_t>(color), 0);
  }
  void add_shield(bool shield) {
    fbb_.AddElement<uint8_t>(Wizard::VT_SHIELD, static_cast<uint8_t>(shield), 0);
  }
  void add_points(int32_t points) {
    fbb_.AddElement<int32_t>(Wizard::VT_POINTS, points, 0);
  }
  void add_x(int32_t x) {
    fbb_.AddElement<int32_t>(Wizard::VT_X, x, 0);
  }
  void add_y(int32_t y) {
    fbb_.AddElement<int32_t>(Wizard::VT_Y, y, 0);
  }
  void add_w(int32_t w) {
    fbb_.AddElement<int32_t>(Wizard::VT_W, w, 0);
  }
  void add_h(int32_t h) {
    fbb_.AddElement<int32_t>(Wizard::VT_H, h, 0);
  }
  void add_aidelay(int32_t aidelay) {
    fbb_.AddElement<int32_t>(Wizard::VT_AIDELAY, aidelay, 0);
  }
  void add_reaction(int32_t reaction) {
    fbb_.AddElement<int32_t>(Wizard::VT_REACTION, reaction, 0);
  }
  void add_gfxset(int32_t gfxset) {
    fbb_.AddElement<int32_t>(Wizard::VT_GFXSET, gfxset, 0);
  }
  void add_follows(int32_t follows) {
    fbb_.AddElement<int32_t>(Wizard::VT_FOLLOWS, follows, 0);
  }
  void add_skid(bool skid) {
    fbb_.AddElement<uint8_t>(Wizard::VT_SKID, static_cast<uint8_t>(skid), 0);
  }
  void add_yoffset(float yoffset) {
    fbb_.AddElement<float>(Wizard::VT_YOFFSET, yoffset, 0.0f);
  }
  void add_speed(const Speed *speed) {
    fbb_.AddStruct(Wizard::VT_SPEED, speed);
  }
  void add_prevspeed(const PrevSpeed *prevspeed) {
    fbb_.AddStruct(Wizard::VT_PREVSPEED, prevspeed);
  }
  void add_aiprior(const Aiprior *aiprior) {
    fbb_.AddStruct(Wizard::VT_AIPRIOR, aiprior);
  }
  void add_control(const Control *control) {
    fbb_.AddStruct(Wizard::VT_CONTROL, control);
  }
  void add_strategic_state(double strategic_state) {
    fbb_.AddElement<double>(Wizard::VT_STRATEGIC_STATE, strategic_state, 0.0);
  }
  void add_joystick(bool joystick) {
    fbb_.AddElement<uint8_t>(Wizard::VT_JOYSTICK, static_cast<uint8_t>(joystick), 0);
  }
  void add_ai(bool ai) {
    fbb_.AddElement<uint8_t>(Wizard::VT_AI, static_cast<uint8_t>(ai), 0);
  }
  void add_keyboard(int32_t keyboard) {
    fbb_.AddElement<int32_t>(Wizard::VT_KEYBOARD, keyboard, 0);
  }
  void add_direction(int32_t direction) {
    fbb_.AddElement<int32_t>(Wizard::VT_DIRECTION, direction, 0);
  }
  void add_frame(int32_t frame) {
    fbb_.AddElement<int32_t>(Wizard::VT_FRAME, frame, 0);
  }
  void add_extra(int32_t extra) {
    fbb_.AddElement<int32_t>(Wizard::VT_EXTRA, extra, 0);
  }
  void add_status(int32_t status) {
    fbb_.AddElement<int32_t>(Wizard::VT_STATUS, status, 0);
  }
  void add_idletime(int32_t idletime) {
    fbb_.AddElement<int32_t>(Wizard::VT_IDLETIME, idletime, 0);
  }
  void add_timer(int32_t timer) {
    fbb_.AddElement<int32_t>(Wizard::VT_TIMER, timer, 0);
  }
  WizardBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  WizardBuilder &operator=(const WizardBuilder &);
  flatbuffers::Offset<Wizard> Finish() {
    const auto end = fbb_.EndTable(start_, 27);
    auto o = flatbuffers::Offset<Wizard>(end);
    return o;
  }
};

inline flatbuffers::Offset<Wizard> CreateWizard(
    flatbuffers::FlatBufferBuilder &_fbb,
    Color color = Color_BLUE,
    bool shield = false,
    int32_t points = 0,
    int32_t x = 0,
    int32_t y = 0,
    int32_t w = 0,
    int32_t h = 0,
    int32_t aidelay = 0,
    int32_t reaction = 0,
    int32_t gfxset = 0,
    int32_t follows = 0,
    bool skid = false,
    float yoffset = 0.0f,
    const Speed *speed = 0,
    const PrevSpeed *prevspeed = 0,
    const Aiprior *aiprior = 0,
    const Control *control = 0,
    double strategic_state = 0.0,
    bool joystick = false,
    bool ai = false,
    int32_t keyboard = 0,
    int32_t direction = 0,
    int32_t frame = 0,
    int32_t extra = 0,
    int32_t status = 0,
    int32_t idletime = 0,
    int32_t timer = 0) {
  WizardBuilder builder_(_fbb);
  builder_.add_strategic_state(strategic_state);
  builder_.add_timer(timer);
  builder_.add_idletime(idletime);
  builder_.add_status(status);
  builder_.add_extra(extra);
  builder_.add_frame(frame);
  builder_.add_direction(direction);
  builder_.add_keyboard(keyboard);
  builder_.add_control(control);
  builder_.add_aiprior(aiprior);
  builder_.add_prevspeed(prevspeed);
  builder_.add_speed(speed);
  builder_.add_yoffset(yoffset);
  builder_.add_follows(follows);
  builder_.add_gfxset(gfxset);
  builder_.add_reaction(reaction);
  builder_.add_aidelay(aidelay);
  builder_.add_h(h);
  builder_.add_w(w);
  builder_.add_y(y);
  builder_.add_x(x);
  builder_.add_points(points);
  builder_.add_ai(ai);
  builder_.add_joystick(joystick);
  builder_.add_skid(skid);
  builder_.add_shield(shield);
  builder_.add_color(color);
  return builder_.Finish();
}

flatbuffers::Offset<Wizard> CreateWizard(flatbuffers::FlatBufferBuilder &_fbb, const WizardT *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

struct GameT : public flatbuffers::NativeTable {
  typedef Game TableType;
  std::unique_ptr<WizardT> wizard0;
  std::unique_ptr<WizardT> wizard1;
  std::unique_ptr<WizardT> wizard2;
  std::unique_ptr<WizardT> wizard3;
  std::unique_ptr<WizardT> wizard4;
  bool stop;
  bool finished;
  bool quit;
  bool playmusic;
  bool playsounds;
  bool gems;
  bool hq;
  bool fixedarena;
  bool tactical;
  int32_t angle;
  std::unique_ptr<Control> control;
  std::unique_ptr<Extra> extra;
  std::string lang;
  std::unique_ptr<Holes> hole1;
  std::unique_ptr<Holes> hole2;
  std::unique_ptr<Holes> hole3;
  std::unique_ptr<Holes> hole4;
  std::unique_ptr<Holes> hole5;
  GameT()
      : stop(false),
        finished(false),
        quit(false),
        playmusic(false),
        playsounds(false),
        gems(false),
        hq(false),
        fixedarena(false),
        tactical(false),
        angle(0) {
  }
};

struct Game FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef GameT NativeTableType;
  enum {
    VT_WIZARD0 = 4,
    VT_WIZARD1 = 6,
    VT_WIZARD2 = 8,
    VT_WIZARD3 = 10,
    VT_WIZARD4 = 12,
    VT_STOP = 14,
    VT_FINISHED = 16,
    VT_QUIT = 18,
    VT_PLAYMUSIC = 20,
    VT_PLAYSOUNDS = 22,
    VT_GEMS = 24,
    VT_HQ = 26,
    VT_FIXEDARENA = 28,
    VT_TACTICAL = 30,
    VT_ANGLE = 32,
    VT_CONTROL = 34,
    VT_EXTRA = 36,
    VT_LANG = 38,
    VT_HOLE1 = 40,
    VT_HOLE2 = 42,
    VT_HOLE3 = 44,
    VT_HOLE4 = 46,
    VT_HOLE5 = 48
  };
  const Wizard *wizard0() const {
    return GetPointer<const Wizard *>(VT_WIZARD0);
  }
  const Wizard *wizard1() const {
    return GetPointer<const Wizard *>(VT_WIZARD1);
  }
  const Wizard *wizard2() const {
    return GetPointer<const Wizard *>(VT_WIZARD2);
  }
  const Wizard *wizard3() const {
    return GetPointer<const Wizard *>(VT_WIZARD3);
  }
  const Wizard *wizard4() const {
    return GetPointer<const Wizard *>(VT_WIZARD4);
  }
  bool stop() const {
    return GetField<uint8_t>(VT_STOP, 0) != 0;
  }
  bool finished() const {
    return GetField<uint8_t>(VT_FINISHED, 0) != 0;
  }
  bool quit() const {
    return GetField<uint8_t>(VT_QUIT, 0) != 0;
  }
  bool playmusic() const {
    return GetField<uint8_t>(VT_PLAYMUSIC, 0) != 0;
  }
  bool playsounds() const {
    return GetField<uint8_t>(VT_PLAYSOUNDS, 0) != 0;
  }
  bool gems() const {
    return GetField<uint8_t>(VT_GEMS, 0) != 0;
  }
  bool hq() const {
    return GetField<uint8_t>(VT_HQ, 0) != 0;
  }
  bool fixedarena() const {
    return GetField<uint8_t>(VT_FIXEDARENA, 0) != 0;
  }
  bool tactical() const {
    return GetField<uint8_t>(VT_TACTICAL, 0) != 0;
  }
  int32_t angle() const {
    return GetField<int32_t>(VT_ANGLE, 0);
  }
  const Control *control() const {
    return GetStruct<const Control *>(VT_CONTROL);
  }
  const Extra *extra() const {
    return GetStruct<const Extra *>(VT_EXTRA);
  }
  const flatbuffers::String *lang() const {
    return GetPointer<const flatbuffers::String *>(VT_LANG);
  }
  const Holes *hole1() const {
    return GetStruct<const Holes *>(VT_HOLE1);
  }
  const Holes *hole2() const {
    return GetStruct<const Holes *>(VT_HOLE2);
  }
  const Holes *hole3() const {
    return GetStruct<const Holes *>(VT_HOLE3);
  }
  const Holes *hole4() const {
    return GetStruct<const Holes *>(VT_HOLE4);
  }
  const Holes *hole5() const {
    return GetStruct<const Holes *>(VT_HOLE5);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_WIZARD0) &&
           verifier.VerifyTable(wizard0()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_WIZARD1) &&
           verifier.VerifyTable(wizard1()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_WIZARD2) &&
           verifier.VerifyTable(wizard2()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_WIZARD3) &&
           verifier.VerifyTable(wizard3()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_WIZARD4) &&
           verifier.VerifyTable(wizard4()) &&
           VerifyField<uint8_t>(verifier, VT_STOP) &&
           VerifyField<uint8_t>(verifier, VT_FINISHED) &&
           VerifyField<uint8_t>(verifier, VT_QUIT) &&
           VerifyField<uint8_t>(verifier, VT_PLAYMUSIC) &&
           VerifyField<uint8_t>(verifier, VT_PLAYSOUNDS) &&
           VerifyField<uint8_t>(verifier, VT_GEMS) &&
           VerifyField<uint8_t>(verifier, VT_HQ) &&
           VerifyField<uint8_t>(verifier, VT_FIXEDARENA) &&
           VerifyField<uint8_t>(verifier, VT_TACTICAL) &&
           VerifyField<int32_t>(verifier, VT_ANGLE) &&
           VerifyField<Control>(verifier, VT_CONTROL) &&
           VerifyField<Extra>(verifier, VT_EXTRA) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_LANG) &&
           verifier.Verify(lang()) &&
           VerifyField<Holes>(verifier, VT_HOLE1) &&
           VerifyField<Holes>(verifier, VT_HOLE2) &&
           VerifyField<Holes>(verifier, VT_HOLE3) &&
           VerifyField<Holes>(verifier, VT_HOLE4) &&
           VerifyField<Holes>(verifier, VT_HOLE5) &&
           verifier.EndTable();
  }
  GameT *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(GameT *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<Game> Pack(flatbuffers::FlatBufferBuilder &_fbb, const GameT* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct GameBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_wizard0(flatbuffers::Offset<Wizard> wizard0) {
    fbb_.AddOffset(Game::VT_WIZARD0, wizard0);
  }
  void add_wizard1(flatbuffers::Offset<Wizard> wizard1) {
    fbb_.AddOffset(Game::VT_WIZARD1, wizard1);
  }
  void add_wizard2(flatbuffers::Offset<Wizard> wizard2) {
    fbb_.AddOffset(Game::VT_WIZARD2, wizard2);
  }
  void add_wizard3(flatbuffers::Offset<Wizard> wizard3) {
    fbb_.AddOffset(Game::VT_WIZARD3, wizard3);
  }
  void add_wizard4(flatbuffers::Offset<Wizard> wizard4) {
    fbb_.AddOffset(Game::VT_WIZARD4, wizard4);
  }
  void add_stop(bool stop) {
    fbb_.AddElement<uint8_t>(Game::VT_STOP, static_cast<uint8_t>(stop), 0);
  }
  void add_finished(bool finished) {
    fbb_.AddElement<uint8_t>(Game::VT_FINISHED, static_cast<uint8_t>(finished), 0);
  }
  void add_quit(bool quit) {
    fbb_.AddElement<uint8_t>(Game::VT_QUIT, static_cast<uint8_t>(quit), 0);
  }
  void add_playmusic(bool playmusic) {
    fbb_.AddElement<uint8_t>(Game::VT_PLAYMUSIC, static_cast<uint8_t>(playmusic), 0);
  }
  void add_playsounds(bool playsounds) {
    fbb_.AddElement<uint8_t>(Game::VT_PLAYSOUNDS, static_cast<uint8_t>(playsounds), 0);
  }
  void add_gems(bool gems) {
    fbb_.AddElement<uint8_t>(Game::VT_GEMS, static_cast<uint8_t>(gems), 0);
  }
  void add_hq(bool hq) {
    fbb_.AddElement<uint8_t>(Game::VT_HQ, static_cast<uint8_t>(hq), 0);
  }
  void add_fixedarena(bool fixedarena) {
    fbb_.AddElement<uint8_t>(Game::VT_FIXEDARENA, static_cast<uint8_t>(fixedarena), 0);
  }
  void add_tactical(bool tactical) {
    fbb_.AddElement<uint8_t>(Game::VT_TACTICAL, static_cast<uint8_t>(tactical), 0);
  }
  void add_angle(int32_t angle) {
    fbb_.AddElement<int32_t>(Game::VT_ANGLE, angle, 0);
  }
  void add_control(const Control *control) {
    fbb_.AddStruct(Game::VT_CONTROL, control);
  }
  void add_extra(const Extra *extra) {
    fbb_.AddStruct(Game::VT_EXTRA, extra);
  }
  void add_lang(flatbuffers::Offset<flatbuffers::String> lang) {
    fbb_.AddOffset(Game::VT_LANG, lang);
  }
  void add_hole1(const Holes *hole1) {
    fbb_.AddStruct(Game::VT_HOLE1, hole1);
  }
  void add_hole2(const Holes *hole2) {
    fbb_.AddStruct(Game::VT_HOLE2, hole2);
  }
  void add_hole3(const Holes *hole3) {
    fbb_.AddStruct(Game::VT_HOLE3, hole3);
  }
  void add_hole4(const Holes *hole4) {
    fbb_.AddStruct(Game::VT_HOLE4, hole4);
  }
  void add_hole5(const Holes *hole5) {
    fbb_.AddStruct(Game::VT_HOLE5, hole5);
  }
  GameBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  GameBuilder &operator=(const GameBuilder &);
  flatbuffers::Offset<Game> Finish() {
    const auto end = fbb_.EndTable(start_, 23);
    auto o = flatbuffers::Offset<Game>(end);
    return o;
  }
};

inline flatbuffers::Offset<Game> CreateGame(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<Wizard> wizard0 = 0,
    flatbuffers::Offset<Wizard> wizard1 = 0,
    flatbuffers::Offset<Wizard> wizard2 = 0,
    flatbuffers::Offset<Wizard> wizard3 = 0,
    flatbuffers::Offset<Wizard> wizard4 = 0,
    bool stop = false,
    bool finished = false,
    bool quit = false,
    bool playmusic = false,
    bool playsounds = false,
    bool gems = false,
    bool hq = false,
    bool fixedarena = false,
    bool tactical = false,
    int32_t angle = 0,
    const Control *control = 0,
    const Extra *extra = 0,
    flatbuffers::Offset<flatbuffers::String> lang = 0,
    const Holes *hole1 = 0,
    const Holes *hole2 = 0,
    const Holes *hole3 = 0,
    const Holes *hole4 = 0,
    const Holes *hole5 = 0) {
  GameBuilder builder_(_fbb);
  builder_.add_hole5(hole5);
  builder_.add_hole4(hole4);
  builder_.add_hole3(hole3);
  builder_.add_hole2(hole2);
  builder_.add_hole1(hole1);
  builder_.add_lang(lang);
  builder_.add_extra(extra);
  builder_.add_control(control);
  builder_.add_angle(angle);
  builder_.add_wizard4(wizard4);
  builder_.add_wizard3(wizard3);
  builder_.add_wizard2(wizard2);
  builder_.add_wizard1(wizard1);
  builder_.add_wizard0(wizard0);
  builder_.add_tactical(tactical);
  builder_.add_fixedarena(fixedarena);
  builder_.add_hq(hq);
  builder_.add_gems(gems);
  builder_.add_playsounds(playsounds);
  builder_.add_playmusic(playmusic);
  builder_.add_quit(quit);
  builder_.add_finished(finished);
  builder_.add_stop(stop);
  return builder_.Finish();
}

inline flatbuffers::Offset<Game> CreateGameDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<Wizard> wizard0 = 0,
    flatbuffers::Offset<Wizard> wizard1 = 0,
    flatbuffers::Offset<Wizard> wizard2 = 0,
    flatbuffers::Offset<Wizard> wizard3 = 0,
    flatbuffers::Offset<Wizard> wizard4 = 0,
    bool stop = false,
    bool finished = false,
    bool quit = false,
    bool playmusic = false,
    bool playsounds = false,
    bool gems = false,
    bool hq = false,
    bool fixedarena = false,
    bool tactical = false,
    int32_t angle = 0,
    const Control *control = 0,
    const Extra *extra = 0,
    const char *lang = nullptr,
    const Holes *hole1 = 0,
    const Holes *hole2 = 0,
    const Holes *hole3 = 0,
    const Holes *hole4 = 0,
    const Holes *hole5 = 0) {
  return flaw::CreateGame(
      _fbb,
      wizard0,
      wizard1,
      wizard2,
      wizard3,
      wizard4,
      stop,
      finished,
      quit,
      playmusic,
      playsounds,
      gems,
      hq,
      fixedarena,
      tactical,
      angle,
      control,
      extra,
      lang ? _fbb.CreateString(lang) : 0,
      hole1,
      hole2,
      hole3,
      hole4,
      hole5);
}

flatbuffers::Offset<Game> CreateGame(flatbuffers::FlatBufferBuilder &_fbb, const GameT *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline WizardT *Wizard::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  auto _o = new WizardT();
  UnPackTo(_o, _resolver);
  return _o;
}

inline void Wizard::UnPackTo(WizardT *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = color(); _o->color = _e; };
  { auto _e = shield(); _o->shield = _e; };
  { auto _e = points(); _o->points = _e; };
  { auto _e = x(); _o->x = _e; };
  { auto _e = y(); _o->y = _e; };
  { auto _e = w(); _o->w = _e; };
  { auto _e = h(); _o->h = _e; };
  { auto _e = aidelay(); _o->aidelay = _e; };
  { auto _e = reaction(); _o->reaction = _e; };
  { auto _e = gfxset(); _o->gfxset = _e; };
  { auto _e = follows(); _o->follows = _e; };
  { auto _e = skid(); _o->skid = _e; };
  { auto _e = yoffset(); _o->yoffset = _e; };
  { auto _e = speed(); if (_e) _o->speed = std::unique_ptr<Speed>(new Speed(*_e)); };
  { auto _e = prevspeed(); if (_e) _o->prevspeed = std::unique_ptr<PrevSpeed>(new PrevSpeed(*_e)); };
  { auto _e = aiprior(); if (_e) _o->aiprior = std::unique_ptr<Aiprior>(new Aiprior(*_e)); };
  { auto _e = control(); if (_e) _o->control = std::unique_ptr<Control>(new Control(*_e)); };
  { auto _e = strategic_state(); _o->strategic_state = _e; };
  { auto _e = joystick(); _o->joystick = _e; };
  { auto _e = ai(); _o->ai = _e; };
  { auto _e = keyboard(); _o->keyboard = _e; };
  { auto _e = direction(); _o->direction = _e; };
  { auto _e = frame(); _o->frame = _e; };
  { auto _e = extra(); _o->extra = _e; };
  { auto _e = status(); _o->status = _e; };
  { auto _e = idletime(); _o->idletime = _e; };
  { auto _e = timer(); _o->timer = _e; };
}

inline flatbuffers::Offset<Wizard> Wizard::Pack(flatbuffers::FlatBufferBuilder &_fbb, const WizardT* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateWizard(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<Wizard> CreateWizard(flatbuffers::FlatBufferBuilder &_fbb, const WizardT *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  auto _color = _o->color;
  auto _shield = _o->shield;
  auto _points = _o->points;
  auto _x = _o->x;
  auto _y = _o->y;
  auto _w = _o->w;
  auto _h = _o->h;
  auto _aidelay = _o->aidelay;
  auto _reaction = _o->reaction;
  auto _gfxset = _o->gfxset;
  auto _follows = _o->follows;
  auto _skid = _o->skid;
  auto _yoffset = _o->yoffset;
  auto _speed = _o->speed ? _o->speed.get() : 0;
  auto _prevspeed = _o->prevspeed ? _o->prevspeed.get() : 0;
  auto _aiprior = _o->aiprior ? _o->aiprior.get() : 0;
  auto _control = _o->control ? _o->control.get() : 0;
  auto _strategic_state = _o->strategic_state;
  auto _joystick = _o->joystick;
  auto _ai = _o->ai;
  auto _keyboard = _o->keyboard;
  auto _direction = _o->direction;
  auto _frame = _o->frame;
  auto _extra = _o->extra;
  auto _status = _o->status;
  auto _idletime = _o->idletime;
  auto _timer = _o->timer;
  return flaw::CreateWizard(
      _fbb,
      _color,
      _shield,
      _points,
      _x,
      _y,
      _w,
      _h,
      _aidelay,
      _reaction,
      _gfxset,
      _follows,
      _skid,
      _yoffset,
      _speed,
      _prevspeed,
      _aiprior,
      _control,
      _strategic_state,
      _joystick,
      _ai,
      _keyboard,
      _direction,
      _frame,
      _extra,
      _status,
      _idletime,
      _timer);
}

inline GameT *Game::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  auto _o = new GameT();
  UnPackTo(_o, _resolver);
  return _o;
}

inline void Game::UnPackTo(GameT *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = wizard0(); if (_e) _o->wizard0 = std::unique_ptr<WizardT>(_e->UnPack(_resolver)); };
  { auto _e = wizard1(); if (_e) _o->wizard1 = std::unique_ptr<WizardT>(_e->UnPack(_resolver)); };
  { auto _e = wizard2(); if (_e) _o->wizard2 = std::unique_ptr<WizardT>(_e->UnPack(_resolver)); };
  { auto _e = wizard3(); if (_e) _o->wizard3 = std::unique_ptr<WizardT>(_e->UnPack(_resolver)); };
  { auto _e = wizard4(); if (_e) _o->wizard4 = std::unique_ptr<WizardT>(_e->UnPack(_resolver)); };
  { auto _e = stop(); _o->stop = _e; };
  { auto _e = finished(); _o->finished = _e; };
  { auto _e = quit(); _o->quit = _e; };
  { auto _e = playmusic(); _o->playmusic = _e; };
  { auto _e = playsounds(); _o->playsounds = _e; };
  { auto _e = gems(); _o->gems = _e; };
  { auto _e = hq(); _o->hq = _e; };
  { auto _e = fixedarena(); _o->fixedarena = _e; };
  { auto _e = tactical(); _o->tactical = _e; };
  { auto _e = angle(); _o->angle = _e; };
  { auto _e = control(); if (_e) _o->control = std::unique_ptr<Control>(new Control(*_e)); };
  { auto _e = extra(); if (_e) _o->extra = std::unique_ptr<Extra>(new Extra(*_e)); };
  { auto _e = lang(); if (_e) _o->lang = _e->str(); };
  { auto _e = hole1(); if (_e) _o->hole1 = std::unique_ptr<Holes>(new Holes(*_e)); };
  { auto _e = hole2(); if (_e) _o->hole2 = std::unique_ptr<Holes>(new Holes(*_e)); };
  { auto _e = hole3(); if (_e) _o->hole3 = std::unique_ptr<Holes>(new Holes(*_e)); };
  { auto _e = hole4(); if (_e) _o->hole4 = std::unique_ptr<Holes>(new Holes(*_e)); };
  { auto _e = hole5(); if (_e) _o->hole5 = std::unique_ptr<Holes>(new Holes(*_e)); };
}

inline flatbuffers::Offset<Game> Game::Pack(flatbuffers::FlatBufferBuilder &_fbb, const GameT* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateGame(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<Game> CreateGame(flatbuffers::FlatBufferBuilder &_fbb, const GameT *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  auto _wizard0 = _o->wizard0 ? CreateWizard(_fbb, _o->wizard0.get(), _rehasher) : 0;
  auto _wizard1 = _o->wizard1 ? CreateWizard(_fbb, _o->wizard1.get(), _rehasher) : 0;
  auto _wizard2 = _o->wizard2 ? CreateWizard(_fbb, _o->wizard2.get(), _rehasher) : 0;
  auto _wizard3 = _o->wizard3 ? CreateWizard(_fbb, _o->wizard3.get(), _rehasher) : 0;
  auto _wizard4 = _o->wizard4 ? CreateWizard(_fbb, _o->wizard4.get(), _rehasher) : 0;
  auto _stop = _o->stop;
  auto _finished = _o->finished;
  auto _quit = _o->quit;
  auto _playmusic = _o->playmusic;
  auto _playsounds = _o->playsounds;
  auto _gems = _o->gems;
  auto _hq = _o->hq;
  auto _fixedarena = _o->fixedarena;
  auto _tactical = _o->tactical;
  auto _angle = _o->angle;
  auto _control = _o->control ? _o->control.get() : 0;
  auto _extra = _o->extra ? _o->extra.get() : 0;
  auto _lang = _o->lang.size() ? _fbb.CreateString(_o->lang) : 0;
  auto _hole1 = _o->hole1 ? _o->hole1.get() : 0;
  auto _hole2 = _o->hole2 ? _o->hole2.get() : 0;
  auto _hole3 = _o->hole3 ? _o->hole3.get() : 0;
  auto _hole4 = _o->hole4 ? _o->hole4.get() : 0;
  auto _hole5 = _o->hole5 ? _o->hole5.get() : 0;
  return flaw::CreateGame(
      _fbb,
      _wizard0,
      _wizard1,
      _wizard2,
      _wizard3,
      _wizard4,
      _stop,
      _finished,
      _quit,
      _playmusic,
      _playsounds,
      _gems,
      _hq,
      _fixedarena,
      _tactical,
      _angle,
      _control,
      _extra,
      _lang,
      _hole1,
      _hole2,
      _hole3,
      _hole4,
      _hole5);
}

inline const flaw::Game *GetGame(const void *buf) {
  return flatbuffers::GetRoot<flaw::Game>(buf);
}

inline bool VerifyGameBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<flaw::Game>(nullptr);
}

inline void FinishGameBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<flaw::Game> root) {
  fbb.Finish(root);
}

inline std::unique_ptr<GameT> UnPackGame(
    const void *buf,
    const flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<GameT>(GetGame(buf)->UnPack(res));
}

}  // namespace flaw

#endif  // FLATBUFFERS_GENERATED_FLAWGAME_FLAW_H_
