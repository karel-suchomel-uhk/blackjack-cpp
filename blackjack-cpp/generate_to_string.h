//
//
//
// This is used for converting enums to string. Not written by me
// source: https://stackoverflow.com/questions/5093460/how-to-convert-an-enum-type-variable-to-a-string
//
//
//

#define ETS_EXP(x) x

#define ETS_CASE(e, x)                                                         \
    case e::x:                                                                 \
        return #x;

#define ETS_FE_0(e)
#define ETS_FE_1(e, x) ETS_CASE(e, x)
#define ETS_FE_2(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_1(e, __VA_ARGS__))
#define ETS_FE_3(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_2(e, __VA_ARGS__))
#define ETS_FE_4(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_3(e, __VA_ARGS__))
#define ETS_FE_5(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_4(e, __VA_ARGS__))
#define ETS_FE_6(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_5(e, __VA_ARGS__))
#define ETS_FE_7(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_6(e, __VA_ARGS__))
#define ETS_FE_8(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_7(e, __VA_ARGS__))
#define ETS_FE_9(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_8(e, __VA_ARGS__))
#define ETS_FE_10(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_9(e, __VA_ARGS__))
#define ETS_FE_11(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_10(e, __VA_ARGS__))
#define ETS_FE_12(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_11(e, __VA_ARGS__))
#define ETS_FE_13(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_12(e, __VA_ARGS__))
#define ETS_FE_14(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_13(e, __VA_ARGS__))
#define ETS_FE_15(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_14(e, __VA_ARGS__))
#define ETS_FE_16(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_15(e, __VA_ARGS__))
#define ETS_FE_17(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_16(e, __VA_ARGS__))
#define ETS_FE_18(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_17(e, __VA_ARGS__))
#define ETS_FE_19(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_18(e, __VA_ARGS__))
#define ETS_FE_20(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_19(e, __VA_ARGS__))
#define ETS_FE_21(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_20(e, __VA_ARGS__))
#define ETS_FE_22(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_21(e, __VA_ARGS__))
#define ETS_FE_23(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_22(e, __VA_ARGS__))
#define ETS_FE_24(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_23(e, __VA_ARGS__))
#define ETS_FE_25(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_24(e, __VA_ARGS__))
#define ETS_FE_26(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_25(e, __VA_ARGS__))
#define ETS_FE_27(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_26(e, __VA_ARGS__))
#define ETS_FE_28(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_27(e, __VA_ARGS__))
#define ETS_FE_29(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_28(e, __VA_ARGS__))
#define ETS_FE_30(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_29(e, __VA_ARGS__))
#define ETS_FE_31(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_30(e, __VA_ARGS__))
#define ETS_FE_32(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_31(e, __VA_ARGS__))
#define ETS_FE_33(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_32(e, __VA_ARGS__))
#define ETS_FE_34(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_33(e, __VA_ARGS__))
#define ETS_FE_35(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_34(e, __VA_ARGS__))
#define ETS_FE_36(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_35(e, __VA_ARGS__))
#define ETS_FE_37(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_36(e, __VA_ARGS__))
#define ETS_FE_38(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_37(e, __VA_ARGS__))
#define ETS_FE_39(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_38(e, __VA_ARGS__))
#define ETS_FE_40(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_39(e, __VA_ARGS__))
#define ETS_FE_41(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_40(e, __VA_ARGS__))
#define ETS_FE_42(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_41(e, __VA_ARGS__))
#define ETS_FE_43(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_42(e, __VA_ARGS__))
#define ETS_FE_44(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_43(e, __VA_ARGS__))
#define ETS_FE_45(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_44(e, __VA_ARGS__))
#define ETS_FE_46(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_45(e, __VA_ARGS__))
#define ETS_FE_47(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_46(e, __VA_ARGS__))
#define ETS_FE_48(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_47(e, __VA_ARGS__))
#define ETS_FE_49(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_48(e, __VA_ARGS__))
#define ETS_FE_50(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_49(e, __VA_ARGS__))
#define ETS_FE_51(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_50(e, __VA_ARGS__))
#define ETS_FE_52(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_51(e, __VA_ARGS__))
#define ETS_FE_53(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_52(e, __VA_ARGS__))
#define ETS_FE_54(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_53(e, __VA_ARGS__))
#define ETS_FE_55(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_54(e, __VA_ARGS__))
#define ETS_FE_56(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_55(e, __VA_ARGS__))
#define ETS_FE_57(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_56(e, __VA_ARGS__))
#define ETS_FE_58(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_57(e, __VA_ARGS__))
#define ETS_FE_59(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_58(e, __VA_ARGS__))
#define ETS_FE_60(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_59(e, __VA_ARGS__))
#define ETS_FE_61(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_60(e, __VA_ARGS__))
#define ETS_FE_62(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_61(e, __VA_ARGS__))
#define ETS_FE_63(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_62(e, __VA_ARGS__))
#define ETS_FE_64(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_63(e, __VA_ARGS__))
#define ETS_FE_65(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_64(e, __VA_ARGS__))
#define ETS_FE_66(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_65(e, __VA_ARGS__))
#define ETS_FE_67(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_66(e, __VA_ARGS__))
#define ETS_FE_68(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_67(e, __VA_ARGS__))
#define ETS_FE_69(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_68(e, __VA_ARGS__))
#define ETS_FE_70(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_69(e, __VA_ARGS__))
#define ETS_FE_71(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_70(e, __VA_ARGS__))
#define ETS_FE_72(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_71(e, __VA_ARGS__))
#define ETS_FE_73(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_72(e, __VA_ARGS__))
#define ETS_FE_74(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_73(e, __VA_ARGS__))
#define ETS_FE_75(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_74(e, __VA_ARGS__))
#define ETS_FE_76(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_75(e, __VA_ARGS__))
#define ETS_FE_77(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_76(e, __VA_ARGS__))
#define ETS_FE_78(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_77(e, __VA_ARGS__))
#define ETS_FE_79(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_78(e, __VA_ARGS__))
#define ETS_FE_80(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_79(e, __VA_ARGS__))
#define ETS_FE_81(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_80(e, __VA_ARGS__))
#define ETS_FE_82(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_81(e, __VA_ARGS__))
#define ETS_FE_83(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_82(e, __VA_ARGS__))
#define ETS_FE_84(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_83(e, __VA_ARGS__))
#define ETS_FE_85(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_84(e, __VA_ARGS__))
#define ETS_FE_86(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_85(e, __VA_ARGS__))
#define ETS_FE_87(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_86(e, __VA_ARGS__))
#define ETS_FE_88(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_87(e, __VA_ARGS__))
#define ETS_FE_89(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_88(e, __VA_ARGS__))
#define ETS_FE_90(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_89(e, __VA_ARGS__))
#define ETS_FE_91(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_90(e, __VA_ARGS__))
#define ETS_FE_92(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_91(e, __VA_ARGS__))
#define ETS_FE_93(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_92(e, __VA_ARGS__))
#define ETS_FE_94(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_93(e, __VA_ARGS__))
#define ETS_FE_95(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_94(e, __VA_ARGS__))
#define ETS_FE_96(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_95(e, __VA_ARGS__))
#define ETS_FE_97(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_96(e, __VA_ARGS__))
#define ETS_FE_98(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_97(e, __VA_ARGS__))
#define ETS_FE_99(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_98(e, __VA_ARGS__))
#define ETS_FE_100(e, x, ...) ETS_CASE(e, x) ETS_EXP(ETS_FE_99(e, __VA_ARGS__))

#define ETS_MATCH_ARGS(                                                        \
    ign0, ign1, ign2, ign3, ign4, ign5, ign6, ign7, ign8, ign9, ign10, ign11,  \
    ign12, ign13, ign14, ign15, ign16, ign17, ign18, ign19, ign20, ign21,      \
    ign22, ign23, ign24, ign25, ign26, ign27, ign28, ign29, ign30, ign31,      \
    ign32, ign33, ign34, ign35, ign36, ign37, ign38, ign39, ign40, ign41,      \
    ign42, ign43, ign44, ign45, ign46, ign47, ign48, ign49, ign50, ign51,      \
    ign52, ign53, ign54, ign55, ign56, ign57, ign58, ign59, ign60, ign61,      \
    ign62, ign63, ign64, ign65, ign66, ign67, ign68, ign69, ign70, ign71,      \
    ign72, ign73, ign74, ign75, ign76, ign77, ign78, ign79, ign80, ign81,      \
    ign82, ign83, ign84, ign85, ign86, ign87, ign88, ign89, ign90, ign91,      \
    ign92, ign93, ign94, ign95, ign96, ign97, ign98, ign99, ign100, name, ...) \
    name

#define ETS_FOR_EACH(e, ...)                                                   \
    ETS_EXP(ETS_MATCH_ARGS(                                                    \
        _0, __VA_ARGS__, ETS_FE_100, ETS_FE_99, ETS_FE_98, ETS_FE_97,          \
        ETS_FE_96, ETS_FE_95, ETS_FE_94, ETS_FE_93, ETS_FE_92, ETS_FE_91,      \
        ETS_FE_90, ETS_FE_89, ETS_FE_88, ETS_FE_87, ETS_FE_86, ETS_FE_85,      \
        ETS_FE_84, ETS_FE_83, ETS_FE_82, ETS_FE_81, ETS_FE_80, ETS_FE_79,      \
        ETS_FE_78, ETS_FE_77, ETS_FE_76, ETS_FE_75, ETS_FE_74, ETS_FE_73,      \
        ETS_FE_72, ETS_FE_71, ETS_FE_70, ETS_FE_69, ETS_FE_68, ETS_FE_67,      \
        ETS_FE_66, ETS_FE_65, ETS_FE_64, ETS_FE_63, ETS_FE_62, ETS_FE_61,      \
        ETS_FE_60, ETS_FE_59, ETS_FE_58, ETS_FE_57, ETS_FE_56, ETS_FE_55,      \
        ETS_FE_54, ETS_FE_53, ETS_FE_52, ETS_FE_51, ETS_FE_50, ETS_FE_49,      \
        ETS_FE_48, ETS_FE_47, ETS_FE_46, ETS_FE_45, ETS_FE_44, ETS_FE_43,      \
        ETS_FE_42, ETS_FE_41, ETS_FE_40, ETS_FE_39, ETS_FE_38, ETS_FE_37,      \
        ETS_FE_36, ETS_FE_35, ETS_FE_34, ETS_FE_33, ETS_FE_32, ETS_FE_31,      \
        ETS_FE_30, ETS_FE_29, ETS_FE_28, ETS_FE_27, ETS_FE_26, ETS_FE_25,      \
        ETS_FE_24, ETS_FE_23, ETS_FE_22, ETS_FE_21, ETS_FE_20, ETS_FE_19,      \
        ETS_FE_18, ETS_FE_17, ETS_FE_16, ETS_FE_15, ETS_FE_14, ETS_FE_13,      \
        ETS_FE_12, ETS_FE_11, ETS_FE_10, ETS_FE_9, ETS_FE_8, ETS_FE_7,         \
        ETS_FE_6, ETS_FE_5, ETS_FE_4, ETS_FE_3, ETS_FE_2, ETS_FE_1,            \
        ETS_FE_0)(e, __VA_ARGS__))

#define GENERATE_TO_STRING(enum_type, ...)                                     \
    constexpr const char* to_string(enum_type val)                             \
    {                                                                          \
        switch (val)                                                           \
        {                                                                      \
            ETS_FOR_EACH(enum_type, __VA_ARGS__)                               \
        }                                                                      \
        return "<unknown>";                                                    \
    }