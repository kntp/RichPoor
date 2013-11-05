/**
 * カードを出す場を扱うクラス
 *
 * カードの集合を保持する
 * @author knaka
 */
#ifndef FIELD_H_
#define FIELD_H_

class Field
{
public:
/**
 * コンストラクタ
 */
	Field(void);
/**
 * デストラクタ
 */
	~Field(void);
/**
 * 場を初期化する 
 */
	void initField(void);
private:
	CardSet	cardset;
};

#endif /* FIELD_H_ */
