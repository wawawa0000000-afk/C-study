# C-study

C++学習用のリポジトリです。以下の2つの目的で構成されています。

1. **C++基礎文法・アルゴリズムの自前実装**
2. **C#からUnreal C++への橋渡し学習**

## 構成

| フォルダ | 目的 | 内容 |
|---|---|---|
| `CppBasics/` | C++基礎文法の確認 | クラス構文、参照、ヘッダー/ソース分離など、C#・Cの知識を起点にC++特有の文法を1つずつ確認するための実験用プロジェクト |
| `CppBridgeLearning/` | Unreal C++への橋渡し学習 | C#で習得したOOP・LINQ・ジェネリクス・例外処理・JSON永続化等の知識を、Unreal C++（UPROPERTY、TMap、Delegate等）でどう書くかを学ぶための検証用Unrealプロジェクト |

> アルゴリズム・データ構造（ソート、探索、動的計画法など）の自前実装も、今後 `CppBasics/` または別フォルダに追加していく予定です。

## 動作環境

- C++17 以降（CppBasics）
- Unreal Engine 5.x / Visual Studio 2022（CppBridgeLearning）

## ビルド方法

### CppBasics（素のC++プロジェクト）
Visual Studio で `CppBasics.sln` を開き、`Ctrl + F5`（デバッグなしで開始）でビルド・実行できます。

```bash
# あるいはコマンドラインから（g++がある場合）
g++ -std=c++17 -o output main.cpp
./output
```

### CppBridgeLearning（Unreal C++プロジェクト）
`CppBridgeLearning.uproject` をダブルクリックして Unreal Editor を起動するか、右クリックして「Generate Visual Studio project files」を実行後、生成された `.sln` を Visual Studio で開いてビルドします。

## 学習の進め方

- 独立した小さな練習課題で概念を掴んでから、本プロジェクトに適用する形で進めています。
- C#の概念とUnreal C++の対応関係を意識しながら学習しています（例：`interface` → `UINTERFACE`、`Dictionary<K,V>` → `TMap<K,V>`、`event`/`Action<T>` → Unreal Delegate など）。