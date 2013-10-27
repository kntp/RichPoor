#ifndef BRAIN_H
#define BRAIN_H
/**
 * プレーヤーの手を考えるクラス
 *
 * 場のカードと手持ちのカードから、出すカードを決定する
 * @author knaka
 */

class Brain
{
public:
/**
 * コンストラクタ
 */
	Brain(void);
/**
 * デストラクタ
 */
	~Brain(void);
/**
 * 打つ手をを取得する
 * @param[in] field 場のカード
 * @param[in] in 手持ちのカード
 * @param[out] out 場に出すカード
 * @retval true 成功
 * @retval false 失敗
 */
	bool selectCard(CardSet *field, CardSet *in, CardSet *out);
private:
};

#endif
