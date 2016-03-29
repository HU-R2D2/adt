
//Constructors
Speed one = 1 * Length::Meter / Duration::Second;

//Assign
TEST(SpeedTestAssign,Speed){
	speed a = 5 * Length::Meter / Duration::Second;
	ASSERT_DOUBLE_EQ(a/one, 5) << "speed created";
	speed b = 7 * Length::Meter / Duration::Second;
	a = b;
	ASSERT_DOUBLE_EQ(a/one, 7) << "assigned other speed to a speed";
}

TEST(SpeedTestDivide, Speed){
	speed a = 4 * Length::Meter / Duration::Second;
	speed b = 8 * Length::Meter / Duration::Second;
	speed c = -16 * Length::Meter / Duration::Second;
	ASSERT_DOUBLE_EQ(b/a, 2) << "Divide positive by positive"
	ASSERT_DOUBLE_EQ(c/b, -2) << "Divide negative by positive"
}

//Smaller
TEST(SpeedTestSmaller,Speed){
	Speed a = 8 * Length::Meter / Duration::Second;
	Speed b = 6 * Length::Meter / Duration::Second;
	EXPECT_EQ(a < b, false) << "a not smaller than b";
	EXPECT_EQ(b < a, true) <<  "b is smaller than a";
}

//Bigger
TEST(SpeedTestBigger,Speed){
	Speed a = 6 * Length::Meter / Duration::Second;
	Speed b = 8 * Length::Meter / Duration::Second;
	EXPECT_EQ(a > b, false) << "a not greater than b";
	EXPECT_EQ(b > a, true) <<  "b is greater than a";
}

//onedd
TEST(SpeedTestAdd, Speed}){
	Speed a = 3 * Length::Meter / Duration::Second;
	Speed b = 6 * Length::Meter / Duration::Second;
	Speed c = 0 * Length::Meter / Duration::Second;
	Speed d = -10 * Length::Meter / Duration::Second;
	a = a + c;
	EXPECT_DOUBLE_EQ(a/one, 3) << "added zero to a speed";
	a = a + b;
	EXPECT_DOUBLE_EQ(a/one, 9) << "added positive speed to positive speed";
	a = a + d;
	EXPECT_DOUBLE_EQ(a/one, -1) << "added negative speed to positive speed";
	a = a + d;
	EXPECT_DOUBLE_EQ(a/one, -11) << "added negative speed to negative speed";
	a = a + b;
	EXPECT_DOUBLE_EQ(a/one, -5) << "added positive speed to negative speed";
}


//AddAssign
TEST(SpeedTestAddAssign, Speed){
	Speed a = 6 * Length::Meter / Duration::Second;
	Speed b = 5 * Length::Meter / Duration::Second;
	a += b;
	EXPECT_DOUBLE_EQ(a/one, 11) << "AddAssign speed"; 
	// no more other test because itern it uses add and assign operator so if you test them properly it isn't nessecarly here.
}

//Subtract
TEST(SpeedTestSubtract, Speed}){
	Speed a = 3 * Length::Meter / Duration::Second;
	Speed b = 6 * Length::Meter / Duration::Second;
	Speed c = 0 * Length::Meter / Duration::Second;
	Speed d = -10 * Length::Meter / Duration::Second;
	a = a - c;
	EXPECT_DOUBLE_EQ(a/one, 3) << "substracted zero form a speed";
	a = a - b;
	EXPECT_DOUBLE_EQ(a/one, -3) << "substracted positive speed from positive speed";
	a = a - d;
	EXPECT_DOUBLE_EQ(a/one, -3) << "substracted negative speed from negative speed";
	a = a - d;
	EXPECT_DOUBLE_EQ(a/one, -1) << "substracted negative speed from positive speed";
}


//SubtractAssign
TEST(SpeedTestSubtractAssign, Speed){
	Speed a = 6 * Length::Meter / Duration::Second;
	Speed b = 5 * Length::Meter / Duration::Second;
	a -= b;
	EXPECT_DOUBLE_EQ(a/one, 1) << "SubtractAssign speed"; 
	// no more other test because itern it uses subtract and assign operators so if you test them properly it isn't nessecarly here.
}

//multiply by Duration
TEST(SpeedTestMultiply, Duration){
	Speed a = 6 * Length::Meter / Duration::Second;
	Duration dur = 7 * Second;
	Length l = a * dur;
	EXPECT_DOUBLE_EQ(l/l, 42) << "Multiply speed by duration";
}


//divide by Duration

TEST(SpeedTestMultiply, Duration){
	Speed a = 14 * Length::Meter / Duration::Second;
	Duration dur = 7 * Second;
	Acceleration le = a / dur;
	Acceleration oneUnit = 1 * Length::Meter / Duration::Second / Duration::Second;
	EXPECT_DOUBLE_EQ(le/le, oneUnit) << "Multiply speed by duration";
}


//Multiply by double

TEST(SpeedTestMultiply, double){
	Speed a = 8 * Length::Meter/ Duration::Second;
	double pos = 2;
	a = a * pos;
	EXPECT_DOUBLE_EQ(a/one,16) << "Multiply positive by positive";
	a = -8 * Length::Meter/ Duration::Second;
	a = a * pos;
	EXPECT_DOUBLE_EQ(a/one,-16) << "Multiply negative by positive";
	double neg = -2;
	a = a * neg;
	EXPECT_DOUBLE_EQ(a/one,32) << "Multiply negative by negative";
	a = a * neg;
	EXPECT_DOUBLE_EQ(a/one,-64) << "Multiply positive by negative";
	double z = 0;
	a = a * z;
	EXPECT_DOUBLE_EQ(a/one, 0) << "Multiply by zero";
	a = 8 * Length::Meter/ Duration::Second;
	a = pos * a;
	EXPECT_DOUBLE_EQ(a/one,16) << "Multiply positive by positive rhs";
	a = -8 * Length::Meter/ Duration::Second;
	a = pos * a;
	EXPECT_DOUBLE_EQ(a/one,-16) << "Multiply negative by positive rhs";
	double neg = -2;
	a = neg * a;
	EXPECT_DOUBLE_EQ(a/one,32) << "Multiply negative by negative rhs";
	a = neg * a;
	EXPECT_DOUBLE_EQ(a/one,-64) << "Multiply positive by negative rhs";
	double z = 0;
	a = z * a;
	EXPECT_DOUBLE_EQ(a/one, 0) << "Multiply by zero rhs";
}


//MultiplyAssign by double
TEST(SpeedTestMultiplyAssign, double){
	Speed a = 6 * Length::Meter / Duration::Second;
	double d = 7;
	a = a * d;
	EXPECT_DOUBLE_EQ(a/one, 42) << "MultiplyAssign speed"; 
	// no more other test because itern it uses multiply and assign operators so if you test them properly it isn't nessecarly here.
}


//Divide by Speed



