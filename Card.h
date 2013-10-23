#ifndef CARD_H
#define CARD_H
/**
 * 一枚のカードを扱うクラス
 *
 * スペード、ダイヤ、ハート、クラブの各１３枚
 * 及びジョーカーを表す
 * @author knaka
 */
class Card {
public:
	static const int SUIT_SPADE = 0;
	static const int SUIT_HEART = 1;
	static const int SUIT_DIAMOND = 2;
	static const int SUIT_CLUB = 3;
	static const int SUIT_JOKER = 4;

/**
 * コンストラクタ
 * @param[in] suit スート
 * @param[in] num 番号
 */
	Card(int suit, int num);
/**
 * デストラクタ
 */
	~Card(void);
/**
 * カードのスートを取得する
 * @return スート
 */
	int getSuit(void);
/**
 * カードの番号を取得する
 * @return 番号
 */
	int getNumber(void);
private:
	int suit;
	int num;
};

/**
 * カードを生成するFactory
 *
 * @author knaka
 */
class CardFactory {
public:
/**
 * コンストラクタ
 */
	CardFactory(void);
/**
 * デストラクタ
 */
	~CardFactory(void);
/**
 * カードを生成する
 *
 * カードを生成し、そのポインタを返す
 * @param[in] suit スート
 * @param[in] num 番号
 * @return 生成されたカードオブジェクトへのポインタ
 */
	static Card *createCard(int suit, int num);
};

/**
 * カードの集合を扱うクラス
 *
 * 複数のカードを集合的に扱う
 * @author knaka
 */
class CardSet {
public:
/**
 * コンストラクタ
 */
	CardSet();
/**
 * デストラクタ
 */
	~CardSet();
/**
 * カードセットをクリアする
 */
	void clearCards(void);
/**
 * カードを追加する
 *
 * カードをカードセットの末尾へ追加する
 * @param[in] cd 追加するカードオブジェクトへのポインタ
 */
	void addCard(Card *cd);
/**
 * カードを挿入する
 *
 * カードをカードセットの先頭へ挿入する
 * @param[in] cd 挿入するカードオブジェクトへのポインタ
 */
	void insertCard(Card *cd);
/**
 * カードをソートする
 *
 * カードセットのカードを番号順に昇順に並び替える
 */
	void sortByNum(void);
/**
 * カードを取り出す
 *
 * カードをカードセットの先頭から取り出す
 * @return 取り出されたカードオブジェクトへのポインタ
 */
	Card *pickCard(void);
/**
 * カードを参照する
 *
 * カードセットの指定された位置のカードを参照する
 * @param[in] 参照したいカードの位置（先頭は０）
 * @param[out] カードの情報を受け取るオブジェクトへのポインタ
 * @retval true 成功
 * @retval false 失敗
 */
	bool checkCard(unsigned int no, Card **cd);
private:
	list<Card*> cardset;
};
#endif /* CARD_H */

