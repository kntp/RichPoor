#ifndef PLAYER_H
#define PLAYER_H
/**
 * ゲームのプレーヤーを扱うクラス
 *
 * カードの集合を保持する
 * Brainに出すカードを問い合わせる
 * @author knaka
 */

class Player
{
public:
	static const int RANK_COMMON = 0;
	static const int RANK_RICH = 1;
	static const int RANK_RICHEST = 2;
	static const int RANK_POOR = 3;
	static const int RANK_POOREST = 4;

/**
 * コンストラクタ
 * @param[in] no プレーヤー番号
 */
	Player(int no);
/**
 * デストラクタ
 */
	~Player(void);
/**
 * プレーヤー番号を取得する
 * @return 番号
 */
	int getPlayerNo(void);
/**
 * プレーヤーの階級を取得する
 * @return 階級
 */
	int getPlayerRank(void);
/**
 * プレーヤーの階級を設定する
 * @param[in] 階級
 */
	void setPlayerRank(int rank);
private:
	int player_no;
	int player_rank;
	CardSet	cardset;
};

#endif
