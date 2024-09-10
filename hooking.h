#define HOOK_DRAW_LIST_PRE(r) if(r) { return; }
#define HOOK_DRAW_LIST_POST(r) (r);
#define HOOK_DRAW_LIST_SPLITTER

namespace ImGui {
    namespace Hooks {
        namespace ImDrawListSplitter {
            void SaveDrawListToSplitter(ImDrawListSplitter &splitter, const ImDrawList *draw_list, int idx);
            void RestoreDrawListFromSplitter(ImDrawListSplitter const &splitter, ImDrawList *draw_list, int idx);
            int EnsureSlotsCapacity(ImDrawListSplitter &splitter, int nSlotsTotal);
            void ResetSlot(ImDrawListSplitter &splitter,int i);
            void InitSlot(ImDrawListSplitter &splitter,int i);
            void InitSlots(ImDrawListSplitter &splitter, int nSlotsToInit);
            void ClearFreeMemory(ImDrawListSplitter &splitter);
            int MergeInitialValue(ImDrawListSplitter &splitter,ImDrawList *drawList);
            int MergeUpdate(ImDrawListSplitter &splitter,int i,int prev);
            void MergeReserve(ImDrawList *drawList,int n);
            void MergeOp(ImDrawListSplitter &splitter,ImDrawList *drawList,int i);
        }
        namespace ImFont {
            namespace Pre {
                inline bool RenderChar(const ImFont *font, ImDrawList* draw_list, float size, const ImVec2& pos, ImU32 col, ImWchar c);
                inline bool RenderText(const ImFont *font, ImDrawList* draw_list, float size, const ImVec2& pos, ImU32 col, const ImVec4& clip_rect, const char* text_begin, const char* text_end, float wrap_width, bool cpu_fine_clip);
            }
        }
        namespace ImDrawList {
            namespace Pre {
                inline bool CreateImDrawList(ImDrawListSharedData* shared_data);

                inline bool AddDrawCmd(ImDrawList *draw_list);
                inline bool _PopUnusedDrawCmd(ImDrawList *draw_list);
                inline bool _ResetForNewFrame(ImDrawList *draw_list);

                inline bool PushClipRect(ImDrawList *draw_list,const ImVec2& clip_rect_min, const ImVec2& clip_rect_max, bool intersect_with_current_clip_rect = false);  // Render-level scissoring. This is passed down to your render function but not used for CPU-side coarse clipping. Prefer using higher-level ImGui::PushClipRect(ImDrawList *draw_list,) to affect logic (ImDrawList *draw_list,hit-testing and widget culling)
                inline bool PushClipRectFullScreen(ImDrawList *draw_list,);
                inline bool PopClipRect(ImDrawList *draw_list,);
                inline bool PushTextureID(ImDrawList *draw_list,ImTextureID texture_id);
                inline bool PopTextureID(ImDrawList *draw_list,);

                inline bool AddLine(ImDrawList *draw_list,const ImVec2& p1, const ImVec2& p2, ImU32 col, float thickness);
                inline bool AddRect(ImDrawList *draw_list,const ImVec2& p_min, const ImVec2& p_max, ImU32 col, float rounding, ImDrawFlags flags, float thickness);
                inline bool AddRectFilled(ImDrawList *draw_list,const ImVec2& p_min, const ImVec2& p_max, ImU32 col, float rounding, ImDrawFlags flags);
                inline bool AddRectFilledMultiColor(ImDrawList *draw_list,const ImVec2& p_min, const ImVec2& p_max, ImU32 col_upr_left, ImU32 col_upr_right, ImU32 col_bot_right, ImU32 col_bot_left);
                inline bool AddQuad(ImDrawList *draw_list,const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, ImU32 col, float thickness);
                inline bool AddQuadFilled(ImDrawList *draw_list,const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, ImU32 col);
                inline bool AddTriangle(ImDrawList *draw_list,const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, ImU32 col, float thickness);
                inline bool AddTriangleFilled(ImDrawList *draw_list,const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, ImU32 col);
                inline bool AddCircle(ImDrawList *draw_list,const ImVec2& center, float radius, ImU32 col, int num_segments, float thickness);
                inline bool AddCircleFilled(ImDrawList *draw_list,const ImVec2& center, float radius, ImU32 col, int num_segments);
                inline bool AddNgon(ImDrawList *draw_list,const ImVec2& center, float radius, ImU32 col, int num_segments, float thickness);
                inline bool AddNgonFilled(ImDrawList *draw_list,const ImVec2& center, float radius, ImU32 col, int num_segments);
                inline bool AddEllipse(ImDrawList *draw_list,const ImVec2& center, const ImVec2& radius, ImU32 col, float rot, int num_segments, float thickness);
                inline bool AddEllipseFilled(ImDrawList *draw_list,const ImVec2& center, const ImVec2& radius, ImU32 col, float rot, int num_segments);
                inline bool AddBezierCubic(ImDrawList *draw_list,const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, ImU32 col, float thickness, int num_segments);
                inline bool AddBezierQuadratic(ImDrawList *draw_list,const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, ImU32 col, float thickness, int num_segments);

                inline bool AddPolyline(ImDrawList *draw_list,const ImVec2* points, int num_points, ImU32 col, ImDrawFlags flags, float thickness);
                inline bool AddConvexPolyFilled(ImDrawList *draw_list,const ImVec2* points, int num_points, ImU32 col);
                inline bool AddConcavePolyFilled(ImDrawList *draw_list,const ImVec2* points, int num_points, ImU32 col);

                inline bool AddImage(ImDrawList *draw_list,ImTextureID user_texture_id, const ImVec2& p_min, const ImVec2& p_max, const ImVec2& uv_min, const ImVec2& uv_max, ImU32 col);
                inline bool AddImageQuad(ImDrawList *draw_list,ImTextureID user_texture_id, const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, const ImVec2& uv1, const ImVec2& uv2, const ImVec2& uv3, const ImVec2& uv4, ImU32 col);
                inline bool AddImageRounded(ImDrawList *draw_list,ImTextureID user_texture_id, const ImVec2& p_min, const ImVec2& p_max, const ImVec2& uv_min, const ImVec2& uv_max, ImU32 col, float rounding, ImDrawFlags flags);

                inline bool PathClear(ImDrawList *draw_list);
                inline bool PathLineTo(ImDrawList *draw_list,const ImVec2& pos);
                inline bool PathLineToMergeDuplicate(ImDrawList *draw_list,const ImVec2& pos);
                inline bool PathFillConvex(ImDrawList *draw_list,ImU32 col);
                inline bool PathFillConcave(ImDrawList *draw_list,ImU32 col);
                inline bool PathStroke(ImDrawList *draw_list,ImU32 col, ImDrawFlags flags, float thickness);
                inline bool PathArcTo(ImDrawList *draw_list,const ImVec2& center, float radius, float a_min, float a_max, int num_segments);
                inline bool PathArcToFast(ImDrawList *draw_list,const ImVec2& center, float radius, int a_min_of_12, int a_max_of_12);
                inline bool PathEllipticalArcTo(ImDrawList *draw_list,const ImVec2& center, const ImVec2& radius, float rot, float a_min, float a_max, int num_segments);
                inline bool PathBezierCubicCurveTo(ImDrawList *draw_list,const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, int num_segments);
                inline bool PathBezierQuadraticCurveTo(ImDrawList *draw_list,const ImVec2& p2, const ImVec2& p3, int num_segments);
                inline bool PathRect(ImDrawList *draw_list,const ImVec2& rect_min, const ImVec2& rect_max, float rounding, ImDrawFlags flags);

                inline bool AddCallback(ImDrawList *draw_list,ImDrawCallback callback, void* callback_data);
                inline bool AddDrawCmd(ImDrawList *draw_list,);

                inline bool PrimReserve(ImDrawList *draw_list,int idx_count, int vtx_count);
                inline bool PrimUnreserve(ImDrawList *draw_list,int idx_count, int vtx_count);
                inline bool PrimRect(ImDrawList *draw_list,const ImVec2& a, const ImVec2& b, ImU32 col);
                inline bool PrimRectUV(ImDrawList *draw_list,const ImVec2& a, const ImVec2& b, const ImVec2& uv_a, const ImVec2& uv_b, ImU32 col);
                inline bool PrimQuadUV(ImDrawList *draw_list,const ImVec2& a, const ImVec2& b, const ImVec2& c, const ImVec2& d, const ImVec2& uv_a, const ImVec2& uv_b, const ImVec2& uv_c, const ImVec2& uv_d, ImU32 col);
                inline bool PrimWriteVtx(ImDrawList *draw_list,const ImVec2& pos, const ImVec2& uv, ImU32 col);
                inline bool PrimWriteIdx(ImDrawList *draw_list,ImDrawIdx idx);
                inline bool PrimVtx(ImDrawList *draw_list,const ImVec2& pos, const ImVec2& uv, ImU32 col);

                inline bool _ResetForNewFrame(ImDrawList *draw_list,);
                inline bool _ClearFreeMemory(ImDrawList *draw_list,);
                inline bool _PopUnusedDrawCmd(ImDrawList *draw_list,);
                inline bool _TryMergeDrawCmds(ImDrawList *draw_list,);
                inline bool _OnChangedClipRect(ImDrawList *draw_list,);
                inline bool _OnChangedTextureID(ImDrawList *draw_list,);
                inline bool _OnChangedVtxOffset(ImDrawList *draw_list,);
            }

            namespace Post {
                void CloneOutput(ImDrawList *draw_list,ImDrawList *dest);
            }
        }
    }
}